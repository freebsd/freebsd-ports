--- src/demo.c.orig	Mon Sep  6 15:02:21 2004
+++ src/demo.c	Mon Sep  6 15:02:35 2004
@@ -451,6 +451,7 @@
     compass_pos = GUPPI_NORTH;
     break;
   default:
+  ;
   }
 
   guppi_element_state_set (state,
