--- src/xslt.c.orig	2019-02-18 18:34:36 UTC
+++ src/xslt.c
@@ -277,7 +277,9 @@ void init_xslt_module() {
 /* XSLT transform functions
  */
 void init_xslt_module() {
+#ifndef __FreeBSD__
 	xmlInitMemory();
+#endif
 	xmlInitParser();
 }
 
