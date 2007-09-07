--- src/lib/config.c.orig	2007-05-07 20:55:25.000000000 +0200
+++ src/lib/config.c	2007-07-12 00:10:55.000000000 +0200
@@ -274,7 +274,7 @@
   int status = NO_ERROR;
   struct in_addr addr;
   struct in6_addr addr6;
-  const char* cszTemplDir = "template";
+  const char* cszTemplDir = "share/gateway6";
 
   // Hard-coded parameters. Not configurable anymore.
   pConf->syslog = FALSE;
