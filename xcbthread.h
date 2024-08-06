#ifndef XCBTHREAD_H
#define XCBTHREAD_H

#include <QThread>
#include "xcb_get.h" // 假设 xcb_get.h 是你的 XCB 获取窗口信息的头文件
#include <QMetaType>
class XcbThread : public QThread
{
    Q_OBJECT

public:
    explicit XcbThread(QObject *parent = nullptr);
    ~XcbThread();

signals:
    void windowInfoChanged(const QString &name, uint id);
    void windowDestroyChanged(uint id);
    void windowInfoChanged_qiantai(const QString &name, uint id);
    void windowInfoChanged_houtai(const QString &name, uint id);
protected:
    void run() override;

private:
    xcb_get xcb_test; // 假设 xcb_get 是你的 XCB 获取窗口信息的类
};


#endif // XCBTHREAD_H