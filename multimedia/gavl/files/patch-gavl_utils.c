FreeBSD doesn't define HOST_NAME_MAX anymore, so provide a fallback for
it and other systems that don't define this macro.

--- gavl/utils.c.orig	2026-01-14 23:43:54 UTC
+++ gavl/utils.c
@@ -36,6 +36,13 @@
 #include <sys/types.h>
 #include <fcntl.h>
 
+#ifndef HOST_NAME_MAX
+#  ifdef _POSIX_HOST_NAME_MAX
+#    define HOST_NAME_MAX _POSIX_HOST_NAME_MAX
+#  else
+#    define HOST_NAME_MAX 255
+#  endif
+#endif
 
 #include <gavl/gavl.h>
 #include <gavl/utils.h>
