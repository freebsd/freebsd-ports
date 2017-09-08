--- unetbootin.h.orig	2017-07-14 05:31:37 UTC
+++ unetbootin.h
@@ -35,6 +35,10 @@ This program is distributed in the hope that it will b
 #include <sys/vfs.h>
 #endif
 
+#ifdef Q_OS_FREEBSD
+#include <sys/mount.h>
+#endif
+
 #ifdef AUTOSUPERGRUBDISK
 #define UNETBOOTINB "Auto Super Grub Disk"
 #define NOEXTERN
@@ -333,6 +337,7 @@ class unetbootin : public QWidget, private Ui::unetboo
     void logText(const QString &text);
     void finishLogging();
     void writeTextToFile(const QString &text, const QString &filePath);
+	void setuppersspace();
 	void fininstall();
 	void rmFile(const QString &fn);
 	void rmFile(QFile &fn);
