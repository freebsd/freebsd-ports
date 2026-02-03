--- core/src/include/baconfig.h	2026-02-02 17:47:37.319878000 -0800
+++ core/src/include/baconfig.h	2026-02-02 17:47:52.554519000 -0800
@@ -560,4 +560,15 @@
 #  define Leave(lvl)
 #endif
 
+#if defined(HAVE_WIN32)
+// mingw/windows does not understand "%zu/%zi" by default
+#  define PRIuz PRIu64
+#  define PRIiz PRIi64
+#  define PRItime "lld"
+#else
+#  define PRIuz "zu"
+#  define PRIiz "zi"
+#  define PRItime "ld"
+#endif
+
 #endif  // BAREOS_INCLUDE_BACONFIG_H_
