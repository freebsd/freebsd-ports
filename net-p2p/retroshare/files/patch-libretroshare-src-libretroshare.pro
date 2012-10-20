--- libretroshare/src/libretroshare.pro.orig	2012-10-08 18:45:10.000000000 +0200
+++ libretroshare/src/libretroshare.pro	2012-10-08 19:26:26.000000000 +0200
@@ -341,6 +341,7 @@
 freebsd-* {
 	INCLUDEPATH *= /usr/local/include/gpgme
 	INCLUDEPATH *= /usr/local/include/glib-2.0
+	INCLUDEPATH += ../../openpgpsdk/src
 
 	QMAKE_CXXFLAGS *= -Dfseeko64=fseeko -Dftello64=ftello -Dstat64=stat -Dstatvfs64=statvfs -Dfopen64=fopen
 
