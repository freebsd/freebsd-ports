--- retroshare-gui/src/retroshare-gui.pro.orig	2016-02-05 19:04:46 UTC
+++ retroshare-gui/src/retroshare-gui.pro
@@ -239,12 +239,16 @@ macx {
 
 freebsd-* {
 	INCLUDEPATH *= /usr/local/include/gpgme
-	LIBS *= -lssl
+	LIBS *= -lssl -lcrypto
 	LIBS *= -lgpgme
 	LIBS *= -lupnp
 	LIBS *= -lgnome-keyring
+	LIBS *= -lz
+	LIBS *= -lixml
+	LIBS *= -lexecinfo
 
-	LIBS += -lsqlite3
+	LIBS += -lsqlcipher
+	LIBS *= -rdynamic
 }
 
 ##################################### Haiku ######################################
