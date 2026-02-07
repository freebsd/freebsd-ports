--- retroshare-gui/src/retroshare-gui.pro.orig	2018-03-13 19:25:38 UTC
+++ retroshare-gui/src/retroshare-gui.pro
@@ -270,12 +270,15 @@ macx {
 
 freebsd-* {
 	INCLUDEPATH *= /usr/local/include/gpgme
-	LIBS *= -lssl
+	LIBS *= -lssl -lcrypto
 	LIBS *= -lgpgme
-	LIBS *= -lupnp
+	LIBS *= -lminiupnpc
 	LIBS *= -lgnome-keyring
+	LIBS *= -lz
+	LIBS *= -lexecinfo
 
-	LIBS += -lsqlite3
+	LIBS += -lsqlcipher
+	LIBS *= -rdynamic
 }
 
 ##################################### Haiku ######################################
