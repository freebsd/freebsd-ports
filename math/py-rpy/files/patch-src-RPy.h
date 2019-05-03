--- src/RPy.h
+++ src/RPy.h
@@ -52,6 +52,13 @@
 #include <Rdefines.h>
 #include <Rinternals.h>
 #include <Rversion.h>
+
+#if (R_VERSION >= R_Version(2,4,0)) 
+#include <Rembedded.h>
+#endif
+
+
+
 #undef _POSIX_C_SOURCE
 #include <Python.h>
 #include <R_ext/Rdynload.h>
@@ -74,7 +81,7 @@
 #  endif
 #endif  /* _WIN32 */
 
-#include <Rdevices.h> /* must follow Graphics.h */
+#include <Rembedded.h> /* must follow Graphics.h */
 
 
 /* Missing definitions from Rinterface.h or RStartup.h */
diff --git src/io.c src/io.c
index 6c7c31d..cb10259 100644
