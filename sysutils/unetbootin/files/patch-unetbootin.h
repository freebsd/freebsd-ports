--- unetbootin.h.orig	2018-04-28 01:24:54 UTC
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
@@ -152,19 +156,13 @@ signals:
 	void finished();
 };
 
-class ubngetrequestheader : public QHttpRequestHeader
-{
-public:
-	ubngetrequestheader(QString urhost, QString urpath);
-};
-
 class randtmpfile : public QFile
 {
 public:
 	randtmpfile(QString rfpath, QString rfextn);
 	static QString getrandfilename(QString rfpath, QString rfextn);
 };
-
+/*
 class nDirListStor : public QObject
 {
 	Q_OBJECT
@@ -178,7 +176,7 @@ class nDirListStor : public QObject (public)
 public slots:
 	void sAppendSelfUrlInfoList(QUrlInfo curDirUrl);
 };
-
+*/
 class unetbootin : public QWidget, private Ui::unetbootinui
 {
 	Q_OBJECT
@@ -280,7 +278,7 @@ class unetbootin : public QWidget, private Ui::unetboo
 	QString searchforgrub2includesfile(QString includesfile, QString archivefile, QStringList archivefileconts, QStringList visitedincludes);
 	QPair<QPair<QStringList, QStringList>, QPair<QStringList, QStringList> > searchforgrub2includesfileL(QString includesfile, QString archivefile, QStringList archivefileconts, QStringList visitedincludes);
 	void downloadfile(QString fileurl, QString targetfile, int minsize);
-	QString downloadpagecontents(QString pageurl);
+	QString downloadpagecontents(QUrl pageurl);
 	QStringList lstFtpDirFiles(QString ldfDirStringUrl, int ldfMinSize, int ldfMaxSize);
 	QStringList lstHttpDirFiles(QString ldfDirStringUrl);
 	QStringList lstNetDirFiles(QString ldfDirStringUrl, int ldfMinSize, int ldfMaxSize);
@@ -333,6 +331,7 @@ class unetbootin : public QWidget, private Ui::unetboo
     void logText(const QString &text);
     void finishLogging();
     void writeTextToFile(const QString &text, const QString &filePath);
+	void setuppersspace();
 	void fininstall();
 	void rmFile(const QString &fn);
 	void rmFile(QFile &fn);
@@ -342,9 +341,9 @@ class unetbootin : public QWidget, private Ui::unetboo
 
 private slots:
 	void on_distroselect_currentIndexChanged(int distroselectIndex);
-	void on_typeselect_currentIndexChanged(int typeselectIndex);
-	void on_dverselect_currentIndexChanged();
-	void on_diskimagetypeselect_currentIndexChanged();
+	void on_typeselect_currentIndexChanged(int);
+	void on_dverselect_currentIndexChanged(int);
+	void on_diskimagetypeselect_currentIndexChanged(int);
 	void on_FloppyFileSelector_clicked();
 	void on_KernelFileSelector_clicked();
 	void on_InitrdFileSelector_clicked();
@@ -353,7 +352,6 @@ private slots:
 	void on_fexitbutton_clicked();
 
 public slots:
-	void dlprogressupdate(int dlbytes, int maxbytes);
 	void dlprogressupdate64(qint64 dlbytes, qint64 maxbytes);
 	void cpprogressupdate64(qint64 dlbytes, qint64 maxbytes);
 	void on_okbutton_clicked();
