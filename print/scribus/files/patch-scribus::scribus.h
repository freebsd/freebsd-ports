--- scribus/scribus.h.orig	Wed Aug 18 04:58:31 2004
+++ scribus/scribus.h	Sun Aug 29 19:34:45 2004
@@ -565,7 +565,7 @@
 	QPopupMenu *toolbarMenu;
 	double mm2pts(int mm);
 	double pts2mm(double pts);
-	void addNewPages(int wo, int where, int numPages, QString based1 = tr("Normal"), QString based2 = tr("Normal"));
+	void addNewPages(int wo, int where, int numPages, QString based1 = QObject::tr("Normal"), QString based2 = QObject::tr("Normal"));
 	QMap<int,QString> FontID;
 	int HaveGS;
 	void *PSDriver;
