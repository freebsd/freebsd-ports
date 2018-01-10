--- include/config.h.orig	1998-10-09 05:08:54 UTC
+++ include/config.h
@@ -30,6 +30,10 @@
 #if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 8)
 #define SP_ANSI_LIB
 #undef SP_NEW_H_MISSING
+#if __GNUC__ > 2
+#define SP_HAVE_TYPENAME
+#undef SP_NO_STD_NAMESPACE
+#endif
 #endif
 #if (__GNUC__ == 2 && __GNUC_MINOR__ >= 8)
 #define SP_NO_STD_NAMESPACE
