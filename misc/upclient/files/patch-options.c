--- src/options.c.orig	Wed Dec 27 00:41:53 2000
+++ src/options.c	Sat Dec 30 06:09:57 2000
@@ -23,11 +23,7 @@
 int  cfg_proxyport				= 8080;
 char cfg_proxyuser[PROXYUSER_MAXLEN+1]		= "";
 char cfg_proxypass[PROXYPASS_MAXLEN+1]		= "";
-#if defined(PLATFORM_BSD)
-int  cfg_sendidle	= 0;
-#else
 int  cfg_sendidle	= 1;
-#endif
 #if defined(PLATFORM_UNIXWARE)
 int  cfg_sendload	= 0;
 #else
@@ -124,11 +120,7 @@
     strcpy(cfg_pidfile, value);
   }
   else if(strcmp(key, "SendIdleTime") == 0) {
-#if defined(PLATFORM_BSD)
-    ;
-#else
     cfg_sendidle = atol(value);
-#endif
   }
   else if(strcmp(key, "SendLoadAvg") == 0) {
 #if defined(PLATFORM_UNIXWARE)
