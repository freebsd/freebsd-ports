--- src/options.h.orig	Mon Sep 30 02:58:36 2002
+++ src/options.h	Sat Oct 19 22:55:19 2002
@@ -60,11 +60,7 @@
 extern char cfg_proxyuser[PROXYUSER_MAXLEN+1];
 extern char cfg_proxypass[PROXYPASS_MAXLEN+1];
 extern int  cfg_sendidle;
-#if defined(PLATFORM_UNIXWARE)
 extern int cfg_sendload;
-#else
-extern int cfg_sendload;
-#endif
 extern int cfg_sendos;
 extern int cfg_sendoslevel;
 extern int cfg_sendcpu;
