--- longlong.h.old	2003-07-29 17:10:52.000000000 +1000
+++ longlong.h	2003-07-29 17:12:16.000000000 +1000
@@ -715,8 +715,10 @@
   } while (0)
 #define count_trailing_zeros(count, x)					\
   do {									\
+    UDItype __cbtmp;							\
     ASSERT ((x) != 0);							\
-    __asm__ ("bsfq %1,%0" : "=r" (count) : "rm" ((UDItype)(x)));	\
+    __asm__ ("bsfq %1,%0" : "=r" (__cbtmp) : "rm" ((UDItype)(x)));	\
+    (count) = __cbtmp;							\
   } while (0)
 #endif /* x86_64 */
 
