--- libretroshare/src/libretroshare.pro.orig	2014-01-28 22:56:57.000000000 +0100
+++ libretroshare/src/libretroshare.pro	2014-10-01 18:48:38.445003534 +0200
@@ -305,6 +305,8 @@
 freebsd-* {
 	INCLUDEPATH *= /usr/local/include/gpgme
 	INCLUDEPATH *= /usr/local/include/glib-2.0
+	INCLUDEPATH *= /usr/local/lib/glib-2.0/include
+	INCLUDEPATH += ../../openpgpsdk/src
 
 	QMAKE_CXXFLAGS *= -Dfseeko64=fseeko -Dftello64=ftello -Dstat64=stat -Dstatvfs64=statvfs -Dfopen64=fopen
 
