--- src/options.c.orig	Mon Dec 18 02:20:24 2000
+++ src/options.c	Sat Dec 30 02:48:01 2000
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
@@ -99,11 +95,7 @@
   else if(strcmp(key, "PidFile") == 0)
     strcpy(cfg_pidfile, value);
   else if(strcmp(key, "SendIdleTime") == 0)
-#if defined(PLATFORM_BSD)
-    ;
-#else
     cfg_sendidle = atol(value);
-#endif
   else if(strcmp(key, "SendLoadAvg") == 0)
 #if defined(PLATFORM_UNIXWARE)
     ;
