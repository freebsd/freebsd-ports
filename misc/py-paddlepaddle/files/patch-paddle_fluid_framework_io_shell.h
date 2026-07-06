-- Fix build on FreeBSD: add <signal.h> for SIGCHLD, SIGPIPE, SIG_DFL, and signal().
-- Add typedef sighandler_t as sig_t (the FreeBSD equivalent of the Linux sighandler_t typedef).
-- Add <unistd.h> for closefrom(2).
--- paddle/fluid/framework/io/shell.h.orig	2026-06-19 18:59:11 UTC
+++ paddle/fluid/framework/io/shell.h
@@ -27,7 +27,13 @@
 #endif
 #include <sys/types.h>
 #ifndef _WIN32
+#include <signal.h>
 #include <sys/wait.h>
+#endif
+#if defined(__FreeBSD__)
+#include <unistd.h>
+/* FreeBSD uses sig_t instead of sighandler_t */
+typedef sig_t sighandler_t;
 #endif
 #include <memory>
 #include <string>
