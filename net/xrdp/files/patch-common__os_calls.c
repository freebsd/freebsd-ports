--- ./common/os_calls.c.orig	Sun Jul 30 01:41:31 2006
+++ ./common/os_calls.c	Mon Jun  4 17:37:42 2007
@@ -1002,6 +1002,8 @@
 g_clearenv(void)
 {
 #if defined(_WIN32)
+#elif defined(__FreeBSD__)
+  environ[0] = NULL;
 #else
   environ = 0;
 #endif
