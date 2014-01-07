--- libclamav/tomsfastmath/mul/fp_mul_comba.c.orig	2014-01-07 17:20:42.000000000 -0200
+++ libclamav/tomsfastmath/mul/fp_mul_comba.c	2014-01-07 17:21:24.000000000 -0200
@@ -53,7 +53,7 @@
      "addl  %%eax,%0     \n\t"                            \
      "adcl  %%edx,%1     \n\t"                            \
      "adcl  $0,%2        \n\t"                            \
-     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "m"(i), "m"(j)  :"%eax","%edx","%cc");
+     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "m"(i), "m"(j)  :"%eax","%edx","cc");
 
 #elif defined(TFM_X86_64)
 /* x86-64 optimized */
@@ -88,7 +88,7 @@
      "addq  %%rax,%0     \n\t"                            \
      "adcq  %%rdx,%1     \n\t"                            \
      "adcq  $0,%2        \n\t"                            \
-     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "g"(i), "g"(j)  :"%rax","%rdx","%cc");
+     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "g"(i), "g"(j)  :"%rax","%rdx","cc");
 
 #elif defined(TFM_SSE2)
 /* use SSE2 optimizations */
@@ -128,7 +128,7 @@
     "movd  %%mm0,%%eax  \n\t"                            \
     "adcl  %%eax,%1     \n\t"                            \
     "adcl  $0,%2        \n\t"                            \
-    :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "m"(i), "m"(j)  :"%eax","%cc");
+    :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "m"(i), "m"(j)  :"%eax","cc");
 
 #elif defined(TFM_ARM)
 /* ARM code */
@@ -155,7 +155,7 @@
 "  ADDS   %0,%0,r0              \n\t"                         \
 "  ADCS   %1,%1,r1              \n\t"                         \
 "  ADC    %2,%2,#0              \n\t"                         \
-:"=r"(c0), "=r"(c1), "=r"(c2) : "0"(c0), "1"(c1), "2"(c2), "r"(i), "r"(j) : "r0", "r1", "%cc");
+:"=r"(c0), "=r"(c1), "=r"(c2) : "0"(c0), "1"(c1), "2"(c2), "r"(i), "r"(j) : "r0", "r1", "cc");
 
 #elif defined(TFM_PPC32)
 /* For 32-bit PPC */
