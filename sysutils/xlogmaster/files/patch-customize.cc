--- src/customize.cc.orig	2007-08-12 19:09:06.000000000 +0200
+++ src/customize.cc	2007-08-12 19:09:28.000000000 +0200
@@ -1847,7 +1847,7 @@
 
   gint default_class0_filter = NO_FILTER;
   if ( data != NULL )
-    default_class0_filter = (gint) data;
+    default_class0_filter = (glong) data;
 
   /* block handlers */
   block_filter_handlers = TRUE;  
