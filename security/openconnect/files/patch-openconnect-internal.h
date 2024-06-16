--- openconnect-internal.h.orig	2023-05-19 16:12:15 UTC
+++ openconnect-internal.h
@@ -85,6 +85,7 @@
 #define N_(s) s
 
 #include <libxml/tree.h>
+#include <libxml/parser.h>
 #include <zlib.h>
 
 #ifdef _WIN32
@@ -133,6 +134,11 @@ extern char **environ;
 extern char **environ;
 #endif
 #include <spawn.h>
+#endif
+
+
+#ifdef __FreeBSD__
+extern char **environ;
 #endif
 
 /* Equivalent of "/dev/null" on Windows.
