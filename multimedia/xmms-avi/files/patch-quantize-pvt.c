--- lib/audioencoder/lame3.70/quantize-pvt.c.orig	Mon Dec 11 18:14:41 2006
+++ lib/audioencoder/lame3.70/quantize-pvt.c	Mon Dec 11 18:14:59 2006
@@ -1030,7 +1030,7 @@
         "jnz loop1\n\n"
         : /* no outputs */
         : "t" (istep), "r" (xr), "r" (adj43asm), "r" (ix), "r" (576 / 4), "m" (rx)
-        : "%eax", "%ebx", "memory", "cc"
+        : "%eax", /* "%ebx", */ "memory", "cc"
       );
   }
 #elif defined (USE_MSC_ASM)
