--- src/libguppiplot/guppi-text-block.c.orig	Mon Sep  6 14:59:32 2004
+++ src/libguppiplot/guppi-text-block.c	Mon Sep  6 14:59:39 2004
@@ -900,6 +900,7 @@
 
     default:
       /* Do nothing. */
+      ;
     }
 
     render_stack_evolve (stack, tt);
