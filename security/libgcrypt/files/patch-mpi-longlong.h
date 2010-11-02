--- ./mpi/longlong.h.orig	2010-02-22 19:04:43.000000000 +0900
+++ ./mpi/longlong.h	2010-11-01 18:25:34.000000000 +0900
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
