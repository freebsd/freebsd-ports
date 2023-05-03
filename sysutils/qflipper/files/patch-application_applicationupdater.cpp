--- application/applicationupdater.cpp.orig	2023-03-27 09:51:38 UTC
+++ application/applicationupdater.cpp
@@ -63,6 +63,9 @@ void ApplicationUpdater::installUpdate(const Flipper::
 
 void ApplicationUpdater::installUpdate(const Flipper::Updates::VersionInfo &versionInfo)
 {
+#ifdef Q_OS_UNIX
+    return;
+#else
 #ifdef Q_OS_WINDOWS
     const auto fileInfo = versionInfo.fileInfo(QStringLiteral("installer"), QStringLiteral("windows/amd64"));
 #elif defined(Q_OS_MAC)
@@ -70,7 +73,7 @@ void ApplicationUpdater::installUpdate(const Flipper::
 #elif defined(Q_OS_LINUX)
     const auto fileInfo = versionInfo.fileInfo(QStringLiteral("AppImage"), QStringLiteral("linux/amd64"));
 #else
-#error "Unsupported OS"
+    #error "Unsupported OS"
 #endif
 
     const auto fileName = QFileInfo(fileInfo.url()).fileName();
@@ -151,6 +154,7 @@ void ApplicationUpdater::installUpdate(const Flipper::
         qCWarning(CATEGORY_SELFUPDATES) << "Downloading the application update package...";
         setState(Downloading);
     }
+#endif
 }
 
 void ApplicationUpdater::setState(ApplicationUpdater::State state)
@@ -213,6 +217,7 @@ bool ApplicationUpdater::performUpdate(const QString &
     return success;
 
 #else
-#error "Unsupported OS"
+#warning "Unsupported OS"
+    return 1;
 #endif
 }
