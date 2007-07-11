--- lib/audioencoder/lame3.70/quantize-pvt.c.orig	Tue Sep 12 18:12:33 2000
+++ lib/audioencoder/lame3.70/quantize-pvt.c	Wed Jul 11 14:46:01 2007
@@ -1029,8 +1029,12 @@
 
         "jnz loop1\n\n"
         : /* no outputs */
+#if __GNUC__ >= 4
+        : "t" (istep), "r" (xr), "r" (adj43asm), "r" (ix), "r" (576 / 4), "g" (rx)
+#else
         : "t" (istep), "r" (xr), "r" (adj43asm), "r" (ix), "r" (576 / 4), "m" (rx)
-        : "%eax", "%ebx", "memory", "cc"
+#endif
+        : "%eax", /* "%ebx", */ "memory", "cc"
       );
   }
 #elif defined (USE_MSC_ASM)
