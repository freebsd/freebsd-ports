--- src/lib/config.c.orig	2009-05-19 18:22:06.000000000 +0200
+++ src/lib/config.c	2009-11-15 17:57:52.000000000 +0100
@@ -264,7 +264,7 @@
 {
   tConf CmdLine;
   gw6c_status status = STATUS_SUCCESS_INIT;
-  const char* cszTemplDir = "template";
+  const char* cszTemplDir = "bin";
 
 
   // Hard-coded parameters. Not configurable anymore.
