--- main.cpp.orig	2016-05-16 08:57:42 UTC
+++ main.cpp
@@ -9,6 +9,8 @@ This program is distributed in the hope that it will b
 
 #include "unetbootin.h"
 
+#include <QMessageBox>
+
 #ifdef Q_OS_WIN32
 
 void configsysUndo(QString uninstPathL)
@@ -292,9 +294,9 @@ int main(int argc, char **argv)
 			}
             argsconc += "\"rootcheck=no\"";
             argsconcSingleQuote += "'rootcheck=no'";
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
             QString gksuarg1;
-            gksuarg1 += QString("bash -c 'QT_X11_NO_MITSHM=1 ");
+            gksuarg1 += QString("sh -c 'QT_X11_NO_MITSHM=1 ");
             gksuarg1 += QString("%1 %2").arg(app.applicationFilePath()).arg(argsconc);
             gksuarg1 += QString("'");
             QStringList gksuargs;
@@ -370,7 +372,7 @@ int main(int argc, char **argv)
 	#ifdef Q_OS_WIN32
 	QSettings chkinst("HKEY_LOCAL_MACHINE\\Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\UNetbootin", QSettings::NativeFormat);
 	#endif
-	#ifdef Q_OS_LINUX
+	#ifdef Q_OS_UNIX
 	QSettings chkinst(QSettings::SystemScope, "UNetbootin");
 	#endif
 #ifndef Q_OS_MAC
@@ -380,18 +382,16 @@ int main(int argc, char **argv)
 		uninstmsgb.setIcon(QMessageBox::Information);
 		uninstmsgb.setWindowTitle(uninstaller::tr("%1 Uninstaller").arg(UNETBOOTINB));
 		uninstmsgb.setText(uninstaller::tr("%1 is currently installed. Remove the existing version?").arg(UNETBOOTINB));
- 		uninstmsgb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
- 		switch (uninstmsgb.exec())
- 		{
- 			case QMessageBox::Ok:
- 			{
- 				ubnUninst();
-			}
-			case QMessageBox::Cancel:
-				break;
-	 		default:
-				break;
- 		}
+		uninstmsgb.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
+		switch (uninstmsgb.exec())
+		{
+		case QMessageBox::Ok:
+			ubnUninst();
+			break;
+		case QMessageBox::Cancel:
+		default:
+			break;
+		}
 		return 0;
 	}
 #endif
@@ -405,7 +405,7 @@ int main(int argc, char **argv)
 	icon.addFile(":/unetbootin_24.png", QSize(24,24));
 	icon.addFile(":/unetbootin_32.png", QSize(32,32));
 	icon.addFile(":/unetbootin_48.png", QSize(48,48));
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 	icon.addFile("/usr/share/pixmaps/unetbootin.png");
 	icon.addFile("/usr/share/pixmaps/unetbootin.xpm");
 #endif
