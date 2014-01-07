--- libclamav/tomsfastmath/sqr/fp_sqr_comba.c.orig	2014-01-07 17:25:18.000000000 -0200
+++ libclamav/tomsfastmath/sqr/fp_sqr_comba.c	2014-01-07 17:25:40.000000000 -0200
@@ -41,7 +41,7 @@
      "addl  %%eax,%0     \n\t"                            \
      "adcl  %%edx,%1     \n\t"                            \
      "adcl  $0,%2        \n\t"                            \
-     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "m"(i) :"%eax","%edx","%cc");
+     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "m"(i) :"%eax","%edx","cc");
 
 #define SQRADD2(i, j)                                     \
 asm(                                            \
@@ -53,7 +53,7 @@
      "addl  %%eax,%0     \n\t"                            \
      "adcl  %%edx,%1     \n\t"                            \
      "adcl  $0,%2        \n\t"                            \
-     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "m"(i), "m"(j)  :"%eax","%edx","%cc");
+     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "m"(i), "m"(j)  :"%eax","%edx","cc");
 
 #define SQRADDSC(i, j)                                    \
 asm(                                                     \
@@ -62,7 +62,7 @@
      "movl  %%eax,%0     \n\t"                            \
      "movl  %%edx,%1     \n\t"                            \
      "xorl  %2,%2        \n\t"                            \
-     :"=r"(sc0), "=r"(sc1), "=r"(sc2): "0"(sc0), "1"(sc1), "2"(sc2), "g"(i), "g"(j) :"%eax","%edx","%cc");
+     :"=r"(sc0), "=r"(sc1), "=r"(sc2): "0"(sc0), "1"(sc1), "2"(sc2), "g"(i), "g"(j) :"%eax","%edx","cc");
 
 #define SQRADDAC(i, j)                                    \
 asm(                                                     \
@@ -71,7 +71,7 @@
      "addl  %%eax,%0     \n\t"                            \
      "adcl  %%edx,%1     \n\t"                            \
      "adcl  $0,%2        \n\t"                            \
-     :"=r"(sc0), "=r"(sc1), "=r"(sc2): "0"(sc0), "1"(sc1), "2"(sc2), "g"(i), "g"(j) :"%eax","%edx","%cc");
+     :"=r"(sc0), "=r"(sc1), "=r"(sc2): "0"(sc0), "1"(sc1), "2"(sc2), "g"(i), "g"(j) :"%eax","%edx","cc");
 
 #define SQRADDDB                                          \
 asm(                                                     \
@@ -81,7 +81,7 @@
      "addl %6,%0         \n\t"                            \
      "adcl %7,%1         \n\t"                            \
      "adcl %8,%2         \n\t"                            \
-     :"=r"(c0), "=r"(c1), "=r"(c2) : "0"(c0), "1"(c1), "2"(c2), "r"(sc0), "r"(sc1), "r"(sc2) : "%cc");
+     :"=r"(c0), "=r"(c1), "=r"(c2) : "0"(c0), "1"(c1), "2"(c2), "r"(sc0), "r"(sc1), "r"(sc2) : "cc");
 
 #elif defined(TFM_X86_64)
 /* x86-64 optimized */
@@ -109,7 +109,7 @@
      "addq  %%rax,%0     \n\t"                            \
      "adcq  %%rdx,%1     \n\t"                            \
      "adcq  $0,%2        \n\t"                            \
-     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "g"(i) :"%rax","%rdx","%cc");
+     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "g"(i) :"%rax","%rdx","cc");
 
 #define SQRADD2(i, j)                                     \
 asm(                                                     \
@@ -121,7 +121,7 @@
      "addq  %%rax,%0     \n\t"                            \
      "adcq  %%rdx,%1     \n\t"                            \
      "adcq  $0,%2        \n\t"                            \
-     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "g"(i), "g"(j)  :"%rax","%rdx","%cc");
+     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "g"(i), "g"(j)  :"%rax","%rdx","cc");
 
 #define SQRADDSC(i, j)                                    \
 asm(                                                     \
@@ -130,7 +130,7 @@
      "movq  %%rax,%0     \n\t"                            \
      "movq  %%rdx,%1     \n\t"                            \
      "xorq  %2,%2        \n\t"                            \
-     :"=r"(sc0), "=r"(sc1), "=r"(sc2): "0"(sc0), "1"(sc1), "2"(sc2), "g"(i), "g"(j) :"%rax","%rdx","%cc");
+     :"=r"(sc0), "=r"(sc1), "=r"(sc2): "0"(sc0), "1"(sc1), "2"(sc2), "g"(i), "g"(j) :"%rax","%rdx","cc");
 
 #define SQRADDAC(i, j)                                                         \
 asm(                                                     \
@@ -139,7 +139,7 @@
      "addq  %%rax,%0     \n\t"                            \
      "adcq  %%rdx,%1     \n\t"                            \
      "adcq  $0,%2        \n\t"                            \
-     :"=r"(sc0), "=r"(sc1), "=r"(sc2): "0"(sc0), "1"(sc1), "2"(sc2), "g"(i), "g"(j) :"%rax","%rdx","%cc");
+     :"=r"(sc0), "=r"(sc1), "=r"(sc2): "0"(sc0), "1"(sc1), "2"(sc2), "g"(i), "g"(j) :"%rax","%rdx","cc");
 
 #define SQRADDDB                                          \
 asm(                                                     \
@@ -149,7 +149,7 @@
      "addq %6,%0         \n\t"                            \
      "adcq %7,%1         \n\t"                            \
      "adcq %8,%2         \n\t"                            \
-     :"=r"(c0), "=r"(c1), "=r"(c2) : "0"(c0), "1"(c1), "2"(c2), "r"(sc0), "r"(sc1), "r"(sc2) : "%cc");
+     :"=r"(c0), "=r"(c1), "=r"(c2) : "0"(c0), "1"(c1), "2"(c2), "r"(sc0), "r"(sc1), "r"(sc2) : "cc");
 
 #elif defined(TFM_SSE2)
 
@@ -181,7 +181,7 @@
      "movd  %%mm0,%%eax  \n\t"                            \
      "adcl  %%eax,%1     \n\t"                            \
      "adcl  $0,%2        \n\t"                            \
-     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "m"(i) :"%eax","%cc");
+     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "m"(i) :"%eax","cc");
 
 #define SQRADD2(i, j)                                     \
 asm(                                            \
@@ -197,7 +197,7 @@
      "addl  %%eax,%0     \n\t"                            \
      "adcl  %%edx,%1     \n\t"                            \
      "adcl  $0,%2        \n\t"                            \
-     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "m"(i), "m"(j)  :"%eax","%edx","%cc");
+     :"=r"(c0), "=r"(c1), "=r"(c2): "0"(c0), "1"(c1), "2"(c2), "m"(i), "m"(j)  :"%eax","%edx","cc");
 
 #define SQRADDSC(i, j)                                                         \
 asm(                                            \
@@ -221,7 +221,7 @@
      "addl  %%eax,%0     \n\t"                            \
      "adcl  %%edx,%1     \n\t"                            \
      "adcl  $0,%2        \n\t"                            \
-     :"=r"(sc0), "=r"(sc1), "=r"(sc2): "0"(sc0), "1"(sc1), "2"(sc2), "m"(i), "m"(j)  :"%eax","%edx","%cc");
+     :"=r"(sc0), "=r"(sc1), "=r"(sc2): "0"(sc0), "1"(sc1), "2"(sc2), "m"(i), "m"(j)  :"%eax","%edx","cc");
 
 #define SQRADDDB                                          \
 asm(                                                     \
@@ -231,7 +231,7 @@
      "addl %6,%0         \n\t"                            \
      "adcl %7,%1         \n\t"                            \
      "adcl %8,%2         \n\t"                            \
-     :"=r"(c0), "=r"(c1), "=r"(c2) : "0"(c0), "1"(c1), "2"(c2), "r"(sc0), "r"(sc1), "r"(sc2) : "%cc");
+     :"=r"(c0), "=r"(c1), "=r"(c2) : "0"(c0), "1"(c1), "2"(c2), "r"(sc0), "r"(sc1), "r"(sc2) : "cc");
 
 #elif defined(TFM_ARM)
 
@@ -260,7 +260,7 @@
 "  ADDS   %0,%0,r0                 \n\t"                         \
 "  ADCS   %1,%1,r1                 \n\t"                         \
 "  ADC    %2,%2,#0                 \n\t"                         \
-:"=r"(c0), "=r"(c1), "=r"(c2) : "0"(c0), "1"(c1), "2"(c2), "r"(i) : "r0", "r1", "%cc");
+:"=r"(c0), "=r"(c1), "=r"(c2) : "0"(c0), "1"(c1), "2"(c2), "r"(i) : "r0", "r1", "cc");
 	
 /* for squaring some of the terms are doubled... */
 #define SQRADD2(i, j)                                            \
@@ -272,13 +272,13 @@
 "  ADDS   %0,%0,r0                 \n\t"                         \
 "  ADCS   %1,%1,r1                 \n\t"                         \
 "  ADC    %2,%2,#0                 \n\t"                         \
-:"=r"(c0), "=r"(c1), "=r"(c2) : "0"(c0), "1"(c1), "2"(c2), "r"(i), "r"(j) : "r0", "r1", "%cc");
+:"=r"(c0), "=r"(c1), "=r"(c2) : "0"(c0), "1"(c1), "2"(c2), "r"(i), "r"(j) : "r0", "r1", "cc");
 
 #define SQRADDSC(i, j)                                           \
 asm(                                                             \
 "  UMULL  %0,%1,%6,%7              \n\t"                         \
 "  SUB    %2,%2,%2                 \n\t"                         \
-:"=r"(sc0), "=r"(sc1), "=r"(sc2) : "0"(sc0), "1"(sc1), "2"(sc2), "r"(i), "r"(j) : "%cc");
+:"=r"(sc0), "=r"(sc1), "=r"(sc2) : "0"(sc0), "1"(sc1), "2"(sc2), "r"(i), "r"(j) : "cc");
 
 #define SQRADDAC(i, j)                                           \
 asm(                                                             \
@@ -286,7 +286,7 @@
 "  ADDS   %0,%0,r0                 \n\t"                         \
 "  ADCS   %1,%1,r1                 \n\t"                         \
 "  ADC    %2,%2,#0                 \n\t"                         \
-:"=r"(sc0), "=r"(sc1), "=r"(sc2) : "0"(sc0), "1"(sc1), "2"(sc2), "r"(i), "r"(j) : "r0", "r1", "%cc");
+:"=r"(sc0), "=r"(sc1), "=r"(sc2) : "0"(sc0), "1"(sc1), "2"(sc2), "r"(i), "r"(j) : "r0", "r1", "cc");
 
 #define SQRADDDB                                                 \
 asm(                                                             \
@@ -296,7 +296,7 @@
 "  ADDS  %0,%0,%3                     \n\t"                      \
 "  ADCS  %1,%1,%4                     \n\t"                      \
 "  ADC   %2,%2,%5                     \n\t"                      \
-:"=r"(c0), "=r"(c1), "=r"(c2) : "r"(sc0), "r"(sc1), "r"(sc2), "0"(c0), "1"(c1), "2"(c2) : "%cc");
+:"=r"(c0), "=r"(c1), "=r"(c2) : "r"(sc0), "r"(sc1), "r"(sc2), "0"(c0), "1"(c1), "2"(c2) : "cc");
 
 #elif defined(TFM_PPC32)
 
@@ -326,7 +326,7 @@
    " mulhwu 16,%6,%6       \n\t" \
    " adde   %1,%1,16       \n\t" \
    " addze  %2,%2          \n\t" \
-:"=r"(c0), "=r"(c1), "=r"(c2):"0"(c0), "1"(c1), "2"(c2), "r"(i):"16","%cc");
+:"=r"(c0), "=r"(c1), "=r"(c2):"0"(c0), "1"(c1), "2"(c2), "r"(i):"16","cc");
 
 /* for squaring some of the terms are doubled... */
 #define SQRADD2(i, j)            \
@@ -339,14 +339,14 @@
    " addc   %0,%0,16       \n\t" \
    " adde   %1,%1,17       \n\t" \
    " addze  %2,%2          \n\t" \
-:"=r"(c0), "=r"(c1), "=r"(c2):"0"(c0), "1"(c1), "2"(c2), "r"(i), "r"(j):"16", "17","%cc");
+:"=r"(c0), "=r"(c1), "=r"(c2):"0"(c0), "1"(c1), "2"(c2), "r"(i), "r"(j):"16", "17","cc");
 
 #define SQRADDSC(i, j)            \
 asm(                              \
    " mullw  %0,%6,%7        \n\t" \
    " mulhwu %1,%6,%7        \n\t" \
    " xor    %2,%2,%2        \n\t" \
-:"=r"(sc0), "=r"(sc1), "=r"(sc2):"0"(sc0), "1"(sc1), "2"(sc2), "r"(i),"r"(j) : "%cc");
+:"=r"(sc0), "=r"(sc1), "=r"(sc2):"0"(sc0), "1"(sc1), "2"(sc2), "r"(i),"r"(j) : "cc");
 
 #define SQRADDAC(i, j)           \
 asm(                             \
@@ -355,7 +355,7 @@
    " mulhwu 16,%6,%7       \n\t" \
    " adde   %1,%1,16       \n\t" \
    " addze  %2,%2          \n\t" \
-:"=r"(sc0), "=r"(sc1), "=r"(sc2):"0"(sc0), "1"(sc1), "2"(sc2), "r"(i), "r"(j):"16", "%cc");
+:"=r"(sc0), "=r"(sc1), "=r"(sc2):"0"(sc0), "1"(sc1), "2"(sc2), "r"(i), "r"(j):"16", "cc");
 
 #define SQRADDDB                  \
 asm(                              \
@@ -365,7 +365,7 @@
    " addc   %0,%0,%3        \n\t" \
    " adde   %1,%1,%4        \n\t" \
    " adde   %2,%2,%5        \n\t" \
-:"=r"(c0), "=r"(c1), "=r"(c2) : "r"(sc0), "r"(sc1), "r"(sc2), "0"(c0), "1"(c1), "2"(c2) : "%cc");
+:"=r"(c0), "=r"(c1), "=r"(c2) : "r"(sc0), "r"(sc1), "r"(sc2), "0"(c0), "1"(c1), "2"(c2) : "cc");
 
 #elif defined(TFM_PPC64)
 /* PPC64 */
@@ -394,7 +394,7 @@
    " mulhdu r16,%6,%6       \n\t" \
    " adde   %1,%1,r16       \n\t" \
    " addze  %2,%2          \n\t" \
-:"=r"(c0), "=r"(c1), "=r"(c2):"0"(c0), "1"(c1), "2"(c2), "r"(i):"r16","%cc");
+:"=r"(c0), "=r"(c1), "=r"(c2):"0"(c0), "1"(c1), "2"(c2), "r"(i):"r16","cc");
 
 /* for squaring some of the terms are doubled... */
 #define SQRADD2(i, j)            \
@@ -407,14 +407,14 @@
    " addc   %0,%0,r16       \n\t" \
    " adde   %1,%1,r17       \n\t" \
    " addze  %2,%2          \n\t" \
-:"=r"(c0), "=r"(c1), "=r"(c2):"0"(c0), "1"(c1), "2"(c2), "r"(i), "r"(j):"r16", "r17","%cc");
+:"=r"(c0), "=r"(c1), "=r"(c2):"0"(c0), "1"(c1), "2"(c2), "r"(i), "r"(j):"r16", "r17","cc");
 
 #define SQRADDSC(i, j)            \
 asm(                              \
    " mulld  %0,%6,%7        \n\t" \
    " mulhdu %1,%6,%7        \n\t" \
    " xor    %2,%2,%2        \n\t" \
-:"=r"(sc0), "=r"(sc1), "=r"(sc2):"0"(sc0), "1"(sc1), "2"(sc2), "r"(i),"r"(j) : "%cc");
+:"=r"(sc0), "=r"(sc1), "=r"(sc2):"0"(sc0), "1"(sc1), "2"(sc2), "r"(i),"r"(j) : "cc");
 
 #define SQRADDAC(i, j)           \
 asm(                             \
@@ -423,7 +423,7 @@
    " mulhdu r16,%6,%7       \n\t" \
    " adde   %1,%1,r16       \n\t" \
    " addze  %2,%2          \n\t" \
-:"=r"(sc0), "=r"(sc1), "=r"(sc2):"0"(sc0), "1"(sc1), "2"(sc2), "r"(i), "r"(j):"r16", "%cc");
+:"=r"(sc0), "=r"(sc1), "=r"(sc2):"0"(sc0), "1"(sc1), "2"(sc2), "r"(i), "r"(j):"r16", "cc");
 
 #define SQRADDDB                  \
 asm(                              \
@@ -433,7 +433,7 @@
    " addc   %0,%0,%3        \n\t" \
    " adde   %1,%1,%4        \n\t" \
    " adde   %2,%2,%5        \n\t" \
-:"=r"(c0), "=r"(c1), "=r"(c2) : "r"(sc0), "r"(sc1), "r"(sc2), "0"(c0), "1"(c1), "2"(c2) : "%cc");
+:"=r"(c0), "=r"(c1), "=r"(c2) : "r"(sc0), "r"(sc1), "r"(sc2), "0"(c0), "1"(c1), "2"(c2) : "cc");
 
 
 #elif defined(TFM_AVR32)
@@ -501,7 +501,7 @@
    " add    %0,%0,%3        \n\t" \
    " adc    %1,%1,%4        \n\t" \
    " adc    %2,%2,%5        \n\t" \
-:"=r"(c0), "=r"(c1), "=r"(c2) : "r"(sc0), "r"(sc1), "r"(sc2), "0"(c0), "1"(c1), "2"(c2) : "%cc");
+:"=r"(c0), "=r"(c1), "=r"(c2) : "r"(sc0), "r"(sc1), "r"(sc2), "0"(c0), "1"(c1), "2"(c2) : "cc");
 
 #elif defined(TFM_MIPS)
 
@@ -571,7 +571,7 @@
    " mflo   %0             \n\t"  \
    " mfhi   %1             \n\t"  \
    " xor    %2,%2,%2       \n\t"  \
-:"=r"(sc0), "=r"(sc1), "=r"(sc2):"0"(sc0), "1"(sc1), "2"(sc2), "r"(i),"r"(j) : "%cc");
+:"=r"(sc0), "=r"(sc1), "=r"(sc2):"0"(sc0), "1"(sc1), "2"(sc2), "r"(i),"r"(j) : "cc");
 
 #define SQRADDAC(i, j)           \
 asm(                             \
