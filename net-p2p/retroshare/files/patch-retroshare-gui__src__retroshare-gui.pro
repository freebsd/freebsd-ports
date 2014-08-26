--- retroshare-gui/src/retroshare-gui.pro.orig	2014-04-10 13:28:51.661832058 +0200
+++ retroshare-gui/src/retroshare-gui.pro	2014-04-10 13:29:31.092831413 +0200
@@ -215,17 +215,22 @@ macx {
 freebsd-* {
 	INCLUDEPATH *= /usr/local/include/gpgme
 	LIBS *= ../../libretroshare/src/lib/libretroshare.a
+	LIBS *= ../../openpgpsdk/src/lib/libops.a -lbz2
 	LIBS *= -lssl
-	LIBS *= -lgpgme
-	LIBS *= -lupnp
+	LIBS *= -lcrypto
+	LIBS *= -lz
+	LIBS *= -lupnp -lixml
+	LIBS *= -lXss -lX11
 	LIBS *= -lgnome-keyring
 	PRE_TARGETDEPS *= ../../libretroshare/src/lib/libretroshare.a
+	PRE_TARGETDEPS *= ../../openpgpsdk/src/lib/libops.a
 
         gxs {
                 LIBS += ../../supportlibs/pegmarkdown/lib/libpegmarkdown.a
-                LIBS += -lsqlite3
+                LIBS += ../../../lib/sqlcipher/.libs/libsqlcipher.a
         }
-
+	LIBS *= -rdynamic
+	DEFINES *= HAVE_XSS # for idle time, libx screensaver extensions
 }
 
 ##################################### OpenBSD ######################################
