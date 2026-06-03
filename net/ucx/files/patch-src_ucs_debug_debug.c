--- src/ucs/debug/debug.c.orig	2026-01-12 18:10:14 UTC
+++ src/ucs/debug/debug.c
@@ -24,6 +24,8 @@
 #include <dlfcn.h>
 #include <link.h>
 #include <dirent.h>
+#include <signal.h>
+#include <stdlib.h>
 #ifdef HAVE_DETAILED_BACKTRACE
 #  include <bfd.h>
 #endif /* HAVE_DETAILED_BACKTRACE */
