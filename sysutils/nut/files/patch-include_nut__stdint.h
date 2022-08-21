--- include/nut_stdint.h.orig	2022-08-24 07:49:23.934399000 -0700
+++ include/nut_stdint.h	2022-08-24 07:56:48.050406000 -0700
@@ -52,6 +52,28 @@
 #endif
 
 /* Printing format for size_t and ssize_t */
+#ifndef PRIuSIZE
+# ifdef PRIsize
+#  define PRIuSIZE PRIsize
+# else
+#  if defined(__MINGW32__) || defined (WIN32)
+#   define PRIuSIZE "llu"
+#  else
+#   define PRIuSIZE "zu"
+#  endif
+# endif
+#endif
+
+#ifndef PRIxSIZE
+#  if defined(__MINGW32__) || defined (WIN32)
+#   define PRIxSIZE "llx"
+#  else
+#   define PRIxSIZE "zx"
+#  endif
+#endif
+
+/* Note: Windows headers are known to define at least "d" values,
+ * so macros below revolve around that and not "i" directly */
 #ifndef PRIsize
 # if defined(__MINGW32__)
 #  define PRIsize "u"
