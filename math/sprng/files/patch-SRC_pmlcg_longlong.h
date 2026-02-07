--- SRC/pmlcg/longlong.h.orig	2024-12-17 18:25:17 UTC
+++ SRC/pmlcg/longlong.h
@@ -211,9 +211,8 @@ UDItype __umulsidi3 (USItype, USItype);
 	     "r" ((USItype) (al)),					\
 	     "rI" ((USItype) (bl)))
 #define umul_ppmm(xh, xl, a, b) \
-{register USItype __t0, __t1, __t2;					\
-  __asm__ ("%@ Inlined umul_ppmm\n"					\
-	   "	mov	%2, %5, lsr #16\n"				\
+{USItype __t0, __t1, __t2;						\
+  __asm__ ("	mov	%2, %5, lsr #16\n"				\
 	   "	mov	%0, %6, lsr #16\n"				\
 	   "	bic	%3, %5, %2, lsl #16\n"				\
 	   "	bic	%4, %6, %0, lsl #16\n"				\

