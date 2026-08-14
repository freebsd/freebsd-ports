--- Linphone/core/notifier/Notifier.cpp.orig
+++ Linphone/core/notifier/Notifier.cpp
@@ -153,7 +153,7 @@
 						    window->setFlags((showAsTool ? Qt::Tool : Qt::WindowStaysOnTopHint) |
 						                     Qt::FramelessWindowHint);
-#ifdef Q_OS_LINUX || Q_OS_WIN
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD) || defined(Q_OS_WIN)
 						    window->setFlag(Qt::WindowDoesNotAcceptFocus);
 #endif
 						    //						    for (auto it = data.begin(); it != data.end(); ++it)
