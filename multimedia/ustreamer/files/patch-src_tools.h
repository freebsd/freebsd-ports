--- src/tools.h.orig	2019-10-11 20:37:25 UTC
+++ src/tools.h
@@ -40,6 +40,13 @@
 #define INLINE inline __attribute__((always_inline))
 #define UNUSED __attribute__((unused))
 
+#ifndef CLOCK_MONOTONIC_RAW
+# ifdef CLOCK_MONOTONIC_FAST
+#  define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC_FAST
+# else
+#  define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
+# endif
+#endif
 
 INLINE char *bool_to_string(bool flag) {
 	return (flag ? "true" : "false");
