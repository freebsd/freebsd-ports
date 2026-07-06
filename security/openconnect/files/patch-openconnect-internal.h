--- openconnect-internal.h.orig	2026-06-13 18:41:22 UTC
+++ openconnect-internal.h
@@ -137,6 +137,11 @@ extern char **environ;
 #include <spawn.h>
 #endif
 
+
+#ifdef __FreeBSD__
+extern char **environ;
+#endif
+
 /* Equivalent of "/dev/null" on Windows.
  * See https://stackoverflow.com/a/44163934
  */
