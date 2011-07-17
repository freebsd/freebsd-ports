--- ./src/ll.c.orig	2011-06-30 20:43:06.000000000 -0400
+++ ./src/ll.c	2011-06-30 20:43:45.000000000 -0400
@@ -118,7 +118,7 @@
 
   if (*caplen < 4) {
     pptrs->iph_ptr = NULL;
-    return;
+    return 0;
   }
 
   do {
