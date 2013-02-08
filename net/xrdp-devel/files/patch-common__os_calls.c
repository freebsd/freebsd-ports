--- common/os_calls.c.orig	2011-03-12 16:10:35.000000000 +0900
+++ common/os_calls.c	2011-03-12 16:34:05.000000000 +0900
@@ -1987,6 +1987,8 @@
 g_clearenv(void)
 {
 #if defined(_WIN32)
+#elif defined(__FreeBSD__)
+  environ[0] = NULL;
 #else
   environ = 0;
 #endif
