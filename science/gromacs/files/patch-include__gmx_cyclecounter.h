--- ./include/gmx_cyclecounter.h.orig	2009-03-31 13:25:55.036329291 +0200
+++ ./include/gmx_cyclecounter.h	2009-03-31 13:26:11.504803886 +0200
@@ -408,7 +408,7 @@
 static __inline__ gmx_cycles_t gmx_cycles_read(void)
 { 
     /* gcc inline assembly on sparc v9 */
-    ticks ret;
+    gmx_cycles_t ret;
     __asm__("rd %%tick, %0" : "=r" (ret));
     return ret;  
 }
