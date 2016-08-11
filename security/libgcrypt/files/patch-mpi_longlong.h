--- mpi/longlong.h.orig	2016-06-16 11:43:39 UTC
+++ mpi/longlong.h
@@ -174,6 +174,7 @@ MA 02111-1307, USA. */
     (pl) = __m0 * __m1; 						\
   } while (0)
 # define UMUL_TIME 46
+# if 0
 # ifndef LONGLONG_STANDALONE
 #  define udiv_qrnnd(q, r, n1, n0, d) \
   do { UDItype __r;							\
@@ -183,6 +184,7 @@ MA 02111-1307, USA. */
 extern UDItype __udiv_qrnnd ();
 #  define UDIV_TIME 220
 # endif /* !LONGLONG_STANDALONE */
+#endif /* 0 */
 #endif /* __alpha */
 
 /***************************************
@@ -1293,7 +1295,7 @@ typedef unsigned int UTItype __attribute
 	     "rJ" ((USItype)(al)),                                      \
 	     "rI" ((USItype)(bl))                                       \
 	   __CLOBBER_CC)
-# if defined (__sparc_v8__) || defined(__sparcv8)
+# if defined (__sparc_v8__) || defined(__sparcv8) || defined(__sparc__)
 /* Don't match immediate range because, 1) it is not often useful,
    2) the 'I' flag thinks of the range as a 13 bit signed interval,
    while we want to match a 13 bit interval, sign extended to 32 bits,
