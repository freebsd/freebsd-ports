--- dclib/dclib.h.orig	Wed Sep  1 14:07:10 2004
+++ dclib/dclib.h	Wed Sep  1 14:07:18 2004
@@ -24,6 +24,9 @@
 
 #include <time.h>
 
+#include <stdarg.h>
+#include <stdio.h>
+
 #ifdef __cplusplus
 extern "C" {
 #endif
@@ -39,7 +42,25 @@
 /**  set dclib verbose */
 DLL_EXPORT void setdclibVerbose( int n );
 
+#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
 #define DPRINTF(...) if (dclibVerbose()) printf(__VA_ARGS__)
+#elif defined __GNUC__
+#define DPRINTF(args...) if (dclibVerbose()) printf(args)
+#else
+static int
+DPRINTF(const char *format,
+        ...)
+{ 
+  int ret = 0;
+  if (dclibVerbose()) {
+    va_list args;
+    va_start (args, format);
+    ret = printf(format, args);
+    va_end (args);
+  }
+  return ret;
+}
+#endif
 
 #ifdef __cplusplus
 }
