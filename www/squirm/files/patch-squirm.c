--- squirm.c.orig	2011-06-23 00:02:30.000000000 +0200
+++ squirm.c	2011-06-23 00:02:46.000000000 +0200
@@ -88,7 +88,7 @@
      print buff to stdout
   */
   if(strlen(in_buff->url) <= 4) {
-    logprint(LOG_FAIL, "strlen in_buff->url = [%d] in main()\n", 
+    logprint(LOG_FAIL, "strlen in_buff->url = [%zu] in main()\n", 
 	strlen(in_buff->url));
     return 1;
   }
