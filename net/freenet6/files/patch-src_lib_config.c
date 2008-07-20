--- src/lib/config.c.orig	2007-11-29 04:27:29.000000000 +1100
+++ src/lib/config.c	2008-07-20 23:56:02.000000000 +1000
@@ -284,7 +284,7 @@
   tConf CmdLine;
   int status = NO_ERROR;
   struct in_addr addr;
-  const char* cszTemplDir = "template";
+  const char* cszTemplDir = "bin";
 #ifdef V4V6_SUPPORT
   struct in6_addr addr6;
 #endif
