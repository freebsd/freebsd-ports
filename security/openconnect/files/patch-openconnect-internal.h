--- openconnect-internal.h.orig	2022-08-27 20:09:15 UTC
+++ openconnect-internal.h
@@ -135,6 +135,11 @@
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
