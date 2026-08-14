--- Linphone/core/App.cpp.orig
+++ Linphone/core/App.cpp
@@ -116,7 +116,7 @@
 
 DEFINE_ABSTRACT_OBJECT(App)
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 const QString AutoStartDirectory(QDir::homePath().append(QStringLiteral("/.config/autostart/")));
 const QString ApplicationsDirectory(QDir::homePath().append(QStringLiteral("/.local/share/applications/")));
 const QString IconsDirectory(QDir::homePath().append(QStringLiteral("/.local/share/icons/hicolor/scalable/apps/")));
@@ -130,7 +130,7 @@
 //		Autostart
 // -----------------------------------------------------------------------------
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 bool App::autoStartEnabled() {
 	const QString confPath(AutoStartDirectory + EXECUTABLE_NAME ".desktop");
 	QFile file(confPath);
@@ -220,7 +220,7 @@
 }
 #endif // ifdef Q_OS_LINUX
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 
 void App::setAutoStart(bool enabled) {
 	if (enabled == mAutoStart) return;
@@ -299,7 +299,7 @@
 	mEventCountNotifier = new EventCountNotifier(this);
 	mDateUpdateTimer.start();
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 	exportDesktopFile();
 #endif
 }
@@ -1074,7 +1074,7 @@
 			allFamilies << QFontDatabase::applicationFontFamilies(id);
 		}
 	}
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 	QDirIterator itFonts(":/linux/font/", QDirIterator::Subdirectories);
 	while (itFonts.hasNext()) {
 		QString ttf = itFonts.next();
@@ -1904,7 +1904,7 @@
 	});
 }
 
-#ifdef Q_OS_LINUX
+#if defined(Q_OS_LINUX) || defined(Q_OS_FREEBSD)
 QString App::getApplicationPath() const {
 	const QString binPath(QCoreApplication::applicationFilePath());
 
