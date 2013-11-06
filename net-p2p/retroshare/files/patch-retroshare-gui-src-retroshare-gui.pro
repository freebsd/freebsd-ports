--- retroshare-gui/src/retroshare-gui.pro.orig	2013-10-21 21:31:11.012605427 +0200
+++ retroshare-gui/src/retroshare-gui.pro	2013-10-21 21:31:53.770609780 +0200
@@ -209,17 +209,19 @@
 freebsd-* {
 	INCLUDEPATH *= /usr/local/include/gpgme
 	LIBS *= ../../libretroshare/src/lib/libretroshare.a
+	LIBS *= ../../openpgpsdk/src/lib/libops.a -lbz2
 	LIBS *= -lssl
 	LIBS *= -lgpgme
 	LIBS *= -lupnp
 	LIBS *= -lgnome-keyring
 	PRE_TARGETDEPS *= ../../libretroshare/src/lib/libretroshare.a
+	PRE_TARGETDEPS *= ../../openpgpsdk/src/lib/libops.a
 
         gxs {
                 LIBS += ../../supportlibs/pegmarkdown/lib/libpegmarkdown.a
                 LIBS += -lsqlite3
         }
-
+	LIBS *= -rdynamic
 }
 
 ##################################### OpenBSD ######################################
