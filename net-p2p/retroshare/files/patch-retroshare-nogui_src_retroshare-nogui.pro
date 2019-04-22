--- retroshare-nogui/src/retroshare-nogui.pro.orig	2019-04-20 14:26:36 UTC
+++ retroshare-nogui/src/retroshare-nogui.pro
@@ -115,10 +115,15 @@ macx {
 
 freebsd-* {
 	INCLUDEPATH *= /usr/local/include/gpgme
-	LIBS *= -lssl
+	LIBS *= -lssl -lcrypto
 	LIBS *= -lgpgme
-	LIBS *= -lupnp
+	LIBS *= -lminiupnpc
 	LIBS *= -lgnome-keyring
+	LIBS *= -lz
+	LIBS *= -lthr
+	LIBS += -lsqlcipher
+	LIBS *= -lexecinfo
+	LIBS *= -rdynamic
 }
 
 ##################################### OpenBSD  ######################################
