--- retroshare-nogui/src/retroshare-nogui.pro.orig	2014-04-10 14:14:22.622840778 +0200
+++ retroshare-nogui/src/retroshare-nogui.pro	2014-04-10 14:14:55.384836372 +0200
@@ -114,12 +114,16 @@
 
 freebsd-* {
 	INCLUDEPATH *= /usr/local/include/gpgme
+	QMAKE_CXXFLAGS *= -Dfseeko64=fseeko -Dftello64=ftello -Dstat64=stat -Dstatvfs64=statvfs -Dfopen64=fopen
 	LIBS *= ../../libretroshare/src/lib/libretroshare.a
-	LIBS *= -lssl
+	LIBS *= ../../openpgpsdk/src/lib/libops.a -lbz2
+	LIBS *= -lssl -lcrypto
 	LIBS *= -lgpgme
-	LIBS *= -lupnp
+	LIBS *= -lupnp -lixml
 	LIBS *= -lgnome-keyring
 	PRE_TARGETDEPS *= ../../libretroshare/src/lib/libretroshare.a
+	PRE_TARGETDEPS *= ../../openpgpsdk/src/lib/libops.a
+	LIBS *= -rdynamic
 }
 
 ##################################### OpenBSD  ######################################
