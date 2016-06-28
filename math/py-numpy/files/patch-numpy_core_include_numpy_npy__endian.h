--- numpy/core/include/numpy/npy_endian.h.orig	2016-06-18 16:15:37 UTC
+++ numpy/core/include/numpy/npy_endian.h
@@ -8,7 +8,7 @@
 
 #ifdef NPY_HAVE_ENDIAN_H
     /* Use endian.h if available */
-    #include <endian.h>
+    #include <sys/endian.h>
 
     #if defined(BYTE_ORDER) && defined(BIG_ENDIAN) && defined(LITTLE_ENDIAN)
         #define NPY_BYTE_ORDER    BYTE_ORDER
