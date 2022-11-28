--- application/applicationupdater.cpp.orig	2022-11-27 21:54:15 UTC
+++ application/applicationupdater.cpp
@@ -57,6 +57,9 @@ void ApplicationUpdater::installUpdate(const Flipper::
 
 void ApplicationUpdater::installUpdate(const Flipper::Updates::VersionInfo &versionInfo)
 {
+#ifdef Q_OS_UNIX
+    return;
+#else
 #ifdef Q_OS_WINDOWS
     const auto fileInfo = versionInfo.fileInfo(QStringLiteral("installer"), QStringLiteral("windows/amd64"));
 #elif defined(Q_OS_MAC)
@@ -64,7 +67,7 @@ void ApplicationUpdater::installUpdate(const Flipper::
 #elif defined(Q_OS_LINUX)
     const auto fileInfo = versionInfo.fileInfo(QStringLiteral("AppImage"), QStringLiteral("linux/amd64"));
 #else
-#error "Unsupported OS"
+    #error "Unsupported OS"
 #endif
 
     const auto fileName = QFileInfo(fileInfo.url()).fileName();
@@ -145,6 +148,7 @@ void ApplicationUpdater::installUpdate(const Flipper::
         qCWarning(CATEGORY_SELFUPDATES) << "Downloading the application update package...";
         setState(State::Downloading);
     }
+#endif
 }
 
 void ApplicationUpdater::setState(State state)
@@ -207,6 +211,7 @@ bool ApplicationUpdater::performUpdate(const QString &
     return success;
 
 #else
-#error "Unsupported OS"
+#warning "Unsupported OS"
+    return 1;
 #endif
 }
