--- Linphone/core/App.hpp.orig
+++ Linphone/core/App.hpp
@@ -178,7 +178,7 @@
 	float getScreenRatio() const;
 	Q_INVOKABLE void setScreenRatio(float ratio);
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 	Q_INVOKABLE void exportDesktopFile();
 
 	QString getApplicationPath() const;
