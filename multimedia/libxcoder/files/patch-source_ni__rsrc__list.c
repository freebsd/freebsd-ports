--- source/ni_rsrc_list.c.orig	2026-10-17 00:01:03 UTC
+++ source/ni_rsrc_list.c
@@ -26,7 +26,7 @@
  *         devices on system
  ******************************************************************************/
 
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
 #include <unistd.h>
 #include <sys/types.h>
 #elif _WIN32
