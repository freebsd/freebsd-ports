--- src/test/plugintest.c.orig	Mon Apr 30 07:44:21 2007
+++ src/test/plugintest.c	Mon Apr 30 07:43:45 2007
@@ -58,8 +58,8 @@
 				      "-libextractor_split");
   list = EXTRACTOR_getKeywords(arg,
 			       "/etc/resolv.conf");
-  if (3 != EXTRACTOR_countKeywords(list)) {
-    printf("Invalid number of keywords (3 != %d)\n",
+  if (4 != EXTRACTOR_countKeywords(list)) {
+    printf("Invalid number of keywords (4 != %d)\n",
 	   EXTRACTOR_countKeywords(list));
     return -1;
   }
