--- ./mpi/longlong.h.orig	2013-07-25 09:10:04.000000000 +0000
+++ ./mpi/longlong.h	2014-06-09 18:53:59.000000000 +0000
@@ -188,8 +188,8 @@
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
   __asm__ ("adds %1, %4, %5\n"                                          \
 	   "adc  %0, %2, %3"                                            \
-	   : "=r" ((USItype)(sh)),                                      \
-	     "=&r" ((USItype)(sl))                                      \
+	   : "=r" ((sh)),                                               \
+	     "=&r" ((sl))                                               \
 	   : "%r" ((USItype)(ah)),                                      \
 	     "rI" ((USItype)(bh)),                                      \
 	     "%r" ((USItype)(al)),                                      \
@@ -197,8 +197,8 @@
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
   __asm__ ("subs %1, %4, %5\n"                                          \
 	   "sbc  %0, %2, %3"                                            \
-	   : "=r" ((USItype)(sh)),                                      \
-	     "=&r" ((USItype)(sl))                                      \
+	   : "=r" ((sh)),                                               \
+	     "=&r" ((sl))                                               \
 	   : "r" ((USItype)(ah)),                                       \
 	     "rI" ((USItype)(bh)),                                      \
 	     "r" ((USItype)(al)),                                       \
@@ -225,10 +225,10 @@
 	   : "r0", "r1", "r2")
 #else
 #define umul_ppmm(xh, xl, a, b)                                         \
-  __asm__ ("%@ Inlined umul_ppmm\n"                                     \
-	   "umull %r1, %r0, %r2, %r3"                                   \
-		   : "=&r" ((USItype)(xh)),                             \
-		     "=r" ((USItype)(xl))                               \
+  __asm__ (                                                             \
+	   "umull %1, %0, %2, %3"                                       \
+		   : "=&r" ((xh)),                                      \
+		     "=r" ((xl))                                        \
 		   : "r" ((USItype)(a)),                                \
 		     "r" ((USItype)(b))                                 \
 		   : "r0", "r1")
@@ -437,8 +437,8 @@
 #define add_ssaaaa(sh, sl, ah, al, bh, bl) \
   __asm__ ("addl %5,%1\n"                                               \
 	   "adcl %3,%0"                                                 \
-	   : "=r" ((USItype)(sh)),                                      \
-	     "=&r" ((USItype)(sl))                                      \
+	   : "=r" (sh),                                                 \
+	     "=&r" (sl)                                                 \
 	   : "%0" ((USItype)(ah)),                                      \
 	     "g" ((USItype)(bh)),                                       \
 	     "%1" ((USItype)(al)),                                      \
@@ -446,22 +446,22 @@
 #define sub_ddmmss(sh, sl, ah, al, bh, bl) \
   __asm__ ("subl %5,%1\n"                                               \
 	   "sbbl %3,%0"                                                 \
-	   : "=r" ((USItype)(sh)),                                      \
-	     "=&r" ((USItype)(sl))                                      \
+	   : "=r" (sh),                                                 \
+	     "=&r" (sl)                                                 \
 	   : "0" ((USItype)(ah)),                                       \
 	     "g" ((USItype)(bh)),                                       \
 	     "1" ((USItype)(al)),                                       \
 	     "g" ((USItype)(bl)))
 #define umul_ppmm(w1, w0, u, v) \
   __asm__ ("mull %3"                                                    \
-	   : "=a" ((USItype)(w0)),                                      \
-	     "=d" ((USItype)(w1))                                       \
+	   : "=a" (w0),                                                 \
+	     "=d" (w1)                                                  \
 	   : "%0" ((USItype)(u)),                                       \
 	     "rm" ((USItype)(v)))
 #define udiv_qrnnd(q, r, n1, n0, d) \
   __asm__ ("divl %4"                                                    \
-	   : "=a" ((USItype)(q)),                                       \
-	     "=d" ((USItype)(r))                                        \
+	   : "=a" (q),                                                  \
+	     "=d" (r)                                                   \
 	   : "0" ((USItype)(n0)),                                       \
 	     "1" ((USItype)(n1)),                                       \
 	     "rm" ((USItype)(d)))
