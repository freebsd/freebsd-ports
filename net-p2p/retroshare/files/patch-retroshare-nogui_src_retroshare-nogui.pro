--- retroshare-nogui/src/retroshare-nogui.pro.orig	2016-03-05 21:29:14 UTC
+++ retroshare-nogui/src/retroshare-nogui.pro
@@ -126,10 +126,16 @@ macx {
 
 freebsd-* {
 	INCLUDEPATH *= /usr/local/include/gpgme
-	LIBS *= -lssl
+	LIBS *= -lssl -lcrypto
 	LIBS *= -lgpgme
 	LIBS *= -lupnp
 	LIBS *= -lgnome-keyring
+	LIBS *= -lz
+	LIBS *= -lixml
+	LIBS *= -lthr
+	LIBS += -lsqlcipher
+	LIBS *= -lexecinfo
+	LIBS *= -rdynamic
 }
 
 ##################################### OpenBSD  ######################################
