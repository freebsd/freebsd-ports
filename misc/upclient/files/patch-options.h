--- src/options.h.orig	Mon Dec 18 01:22:43 2000
+++ src/options.h	Sat Dec 30 02:49:11 2000
@@ -33,19 +33,11 @@
 extern int  cfg_proxyport;
 extern char cfg_proxyuser[PROXYUSER_MAXLEN+1];
 extern char cfg_proxypass[PROXYPASS_MAXLEN+1];
-#if defined(PLATFORM_BSD)
 extern int  cfg_sendidle;
-#else
-extern int  cfg_sendidle;
-#endif
-#if defined(PLATFORM_UNIXWARE)
-extern cfg_sendload;
-#else
-extern cfg_sendload;
-#endif
-extern cfg_sendos;
-extern cfg_sendoslevel;
-extern cfg_sendcpu;
+extern int  cfg_sendload;
+extern int  cfg_sendos;
+extern int  cfg_sendoslevel;
+extern int  cfg_sendcpu;
 
 /* External global variables: set to reflect config options */
 extern int have_proxyserver;
