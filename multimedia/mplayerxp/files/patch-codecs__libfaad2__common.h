--- codecs/libfaad2/common.h.orig	Mon Oct  2 18:33:38 2006
+++ codecs/libfaad2/common.h	Mon Oct  2 18:34:46 2006
@@ -327,21 +317,91 @@
       *y1 = MUL_F(x1, c1) + MUL_F(x2, c2);
       *y2 = MUL_F(x2, c1) - MUL_F(x1, c2);
   }
+
+  #if defined(HAVE_LRINTF)
+    #define HAS_LRINTF
+  #elif defined(_WIN32) && !defined(__MINGW32__) && !defined(HAVE_LRINTF)
+    #define HAS_LRINTF
+    static INLINE int lrintf(float f)
+    {
+        int i;
+        __asm
+        {
+            fld   f
+            fistp i
+        }
+        return i;
+    }
+  #elif (defined(__i386__) && defined(__GNUC__)) && !defined(HAVE_LRINTF)
+    #define HAS_LRINTF
+    // from http://www.stereopsis.com/FPU.html
+    static INLINE int lrintf(float f)
+    {
+        int i;
+        __asm__ __volatile__ (
+            "flds %1        \n\t"
+            "fistpl %0      \n\t"
+            : "=m" (i)
+            : "m" (f));
+        return i;
+    }
+  #endif
+
+
+  #ifdef __ICL /* only Intel C compiler has fmath ??? */
+
+    #include <mathf.h>
+
+    #define sin sinf
+    #define cos cosf
+    #define log logf
+    #define floor floorf
+    #define ceil ceilf
+    #define sqrt sqrtf
+
+  #else
+
+#include <math.h>
+
+#ifdef HAVE_LRINTF
+#  define HAS_LRINTF
+#  define _ISOC9X_SOURCE 1
+#  define _ISOC99_SOURCE 1
+#  define __USE_ISOC9X   1
+#  define __USE_ISOC99   1
 #endif
 
-static inline long int lrintf(float x)
-{
-#if defined( ARCH_X86 ) || defined(ARCH_X86_64)
-    int32_t i;
-    asm volatile(
-        "fistpl %0\n\t"
-        : "=m" (i) : "t" (x) : "st"
-    );
-    return i;
-#else
-    return ((int32_t)(x));
+#ifdef HAVE_SINF
+#  define sin sinf
+#error
+#endif
+#ifdef HAVE_COSF
+#  define cos cosf
+#endif
+#ifdef HAVE_LOGF
+#  define log logf
+#endif
+#ifdef HAVE_EXPF
+#  define exp expf
+#endif
+#ifdef HAVE_FLOORF
+#  define floor floorf
+#endif
+#ifdef HAVE_CEILF
+#  define ceil ceilf
+#endif
+#ifdef HAVE_SQRTF
+#  define sqrt sqrtf
+#endif
+
+  #endif
+
+#endif
+
+#ifndef HAS_LRINTF
+/* standard cast */
+#define lrintf(f) ((int32_t)(f))
 #endif
-}
 
 typedef real_t complex_t[2];
 #define RE(A) A[0]
