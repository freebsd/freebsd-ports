--- src/libguppiplot/guppi-layout-constraint.c.orig	Mon Sep  6 15:00:27 2004
+++ src/libguppiplot/guppi-layout-constraint.c	Mon Sep  6 15:00:36 2004
@@ -165,6 +165,7 @@
 
   default:
     /* Fall through, do nothing. */
+    ;
   }
 
   ti = term_info_new (type, factor, geom);
