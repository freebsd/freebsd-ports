--- libretroshare/src/libretroshare.pro.orig	2016-02-05 19:04:46 UTC
+++ libretroshare/src/libretroshare.pro
@@ -293,7 +293,7 @@ mac {
 
 freebsd-* {
 	INCLUDEPATH *= /usr/local/include/gpgme
-	INCLUDEPATH *= /usr/local/include/glib-2.0
+	INCLUDEPATH += $$system(pkg-config --cflags glib-2.0 | sed -e "s/-I//g")
 
 	QMAKE_CXXFLAGS *= -Dfseeko64=fseeko -Dftello64=ftello -Dstat64=stat -Dstatvfs64=statvfs -Dfopen64=fopen
 
