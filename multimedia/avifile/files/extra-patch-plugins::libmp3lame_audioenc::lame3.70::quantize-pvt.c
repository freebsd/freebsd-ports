--- plugins/libmp3lame_audioenc/lame3.70/quantize-pvt.c.orig	Fri Aug  6 13:59:16 2004
+++ plugins/libmp3lame_audioenc/lame3.70/quantize-pvt.c	Fri Aug  6 14:11:28 2004
@@ -976,6 +976,7 @@
   {
       int rx[4];
       __asm__ __volatile__(
+        "\n\npush %%edx\n\t"
         "\n\nloop1:\n\t"
 
         "fld" F8type " 0(%1)\n\t"
@@ -1007,18 +1008,18 @@
         "dec %4\n\t"
 
         "movl %5, %%eax\n\t"
-        "movl 4+%5, %%ebx\n\t"
+        "movl 4+%5, %%edx\n\t"
         "fxch %%st(1)\n\t"
         "fadd" F8type " (%2,%%eax," F8size ")\n\t"
         "fxch %%st(3)\n\t"
-        "fadd" F8type " (%2,%%ebx," F8size ")\n\t"
+        "fadd" F8type " (%2,%%edx," F8size ")\n\t"
 
         "movl 8+%5, %%eax\n\t"
-        "movl 12+%5, %%ebx\n\t"
+        "movl 12+%5, %%edx\n\t"
         "fxch %%st(2)\n\t"
         "fadd" F8type " (%2,%%eax," F8size ")\n\t"
         "fxch %%st(1)\n\t"
-        "fadd" F8type " (%2,%%ebx," F8size ")\n\t"
+        "fadd" F8type " (%2,%%edx," F8size ")\n\t"
 
         "fxch %%st(3)\n\t"
         "fistpl -16(%3)\n\t"
@@ -1028,9 +1029,10 @@
         "fistpl -4(%3)\n\t"
 
         "jnz loop1\n\n"
+        "pop %%edx\n\n"
         : /* no outputs */
         : "t" (istep), "r" (xr), "r" (adj43asm), "r" (ix), "r" (576 / 4), "m" (rx)
-        : "%eax", "%ebx", "memory", "cc"
+	: "%eax", "memory", "cc"
       );
   }
 #elif defined (USE_MSC_ASM)
