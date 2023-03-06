--- src/notifications/Manager.h.orig	2023-02-24 22:16:17 UTC
+++ src/notifications/Manager.h
@@ -55,9 +55,7 @@ public slots:
 #if defined(NHEKO_DBUS_SYS)
 public:
     void closeNotifications(QString roomId);
-#if defined(Q_OS_LINUX)
     void closeAllNotifications();
-#endif
 
 private:
     QDBusInterface dbus;
