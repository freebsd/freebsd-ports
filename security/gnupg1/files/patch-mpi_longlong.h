--- mpi/longlong.h.orig	2015-12-19 14:08:22 UTC
+++ mpi/longlong.h
@@ -184,8 +184,8 @@ extern UDItype __udiv_qrnnd ();
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
@@ -193,8 +193,8 @@ extern UDItype __udiv_qrnnd ();
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
@@ -221,10 +221,10 @@ extern UDItype __udiv_qrnnd ();
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
