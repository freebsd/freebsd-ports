--- lib/arithmetic_sse_double.h.orig	2010-06-08 08:17:38.000000000 +0800
+++ lib/arithmetic_sse_double.h	2010-06-08 08:19:41.000000000 +0800
@@ -26,7 +26,6 @@
 /* $Id: arithmetic_sse_double.h 65 2010-01-29 12:19:16Z naoaki $ */
 
 #include <stdlib.h>
-#include <malloc.h>
 #include <memory.h>
 
 #if     1400 <= _MSC_VER
@@ -37,6 +36,8 @@
 #include <emmintrin.h>
 #endif/*HAVE_EMMINTRIN_H*/
 
+#define memalign(A,B)  malloc(B)
+
 inline static void* vecalloc(size_t size)
 {
 #ifdef	_MSC_VER
