--- src/options.h.orig	Sat Jun 16 17:45:50 2001
+++ src/options.h	Sun Nov 18 16:08:56 2001
@@ -34,11 +34,7 @@
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
