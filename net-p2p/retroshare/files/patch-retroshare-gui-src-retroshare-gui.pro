--- retroshare-gui/src/retroshare-gui.pro.orig	2012-10-29 21:09:06.932916323 +0100
+++ retroshare-gui/src/retroshare-gui.pro	2012-10-29 21:10:17.747920258 +0100
@@ -175,11 +175,14 @@
 freebsd-* {
 	INCLUDEPATH *= /usr/local/include/gpgme
 	LIBS *= ../../libretroshare/src/lib/libretroshare.a
+	LIBS += ../../openpgpsdk/src/lib/libops.a -lbz2
 	LIBS *= -lssl
 	LIBS *= -lgpgme
 	LIBS *= -lupnp
 	LIBS *= -lgnome-keyring
 	PRE_TARGETDEPS *= ../../libretroshare/src/lib/libretroshare.a
+	# plugins need this
+	QMAKE_LFLAGS *= -rdynamic
 }
 
 ############################## Common stuff ######################################
