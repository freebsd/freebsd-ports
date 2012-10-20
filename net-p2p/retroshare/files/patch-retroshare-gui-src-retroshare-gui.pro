--- retroshare-gui/src/retroshare-gui.pro.orig	2012-10-08 19:37:47.000000000 +0200
+++ retroshare-gui/src/retroshare-gui.pro	2012-10-08 20:10:51.000000000 +0200
@@ -175,6 +175,7 @@
 freebsd-* {
 	INCLUDEPATH *= /usr/local/include/gpgme
 	LIBS *= ../../libretroshare/src/lib/libretroshare.a
+	LIBS += ../../openpgpsdk/src/lib/libops.a -lbz2
 	LIBS *= -lssl
 	LIBS *= -lgpgme
 	LIBS *= -lupnp
