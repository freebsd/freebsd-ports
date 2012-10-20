--- retroshare-nogui/src/retroshare-nogui.pro.orig	2012-10-08 22:44:45.000000000 +0200
+++ retroshare-nogui/src/retroshare-nogui.pro	2012-10-08 22:46:13.000000000 +0200
@@ -78,6 +78,7 @@
 freebsd-* {
 	INCLUDEPATH *= /usr/local/include/gpgme
 	LIBS *= ../../libretroshare/src/lib/libretroshare.a
+	LIBS += ../../openpgpsdk/src/lib/libops.a -lbz2
 	LIBS *= -lssl
 	LIBS *= -lgpgme
 	LIBS *= -lupnp
