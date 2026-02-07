--- avidemux_core/ADM_core/src/ADM_memsupport.cpp.orig	2019-08-15 07:25:39 UTC
+++ avidemux_core/ADM_core/src/ADM_memsupport.cpp
@@ -23,7 +23,7 @@
  *   (at your option) any later version.                                   *
  *                                                                         *
  ***************************************************************************/
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 #include "ADM_default.h"
@@ -74,7 +74,7 @@ void ADM_dezalloc(void *ptr)
 
 	ADM_aligned_free(ptr);
 }
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 void *ADM_aligned_alloc(size_t size)
 {
     return malloc(size);
