--- utils/c-icap-stretch.c.orig	2024-10-04 08:22:44 UTC
+++ utils/c-icap-stretch.c
@@ -71,7 +71,7 @@
 
 int pid_to_int(ci_thread_t id)
 {
-#if defined(_WIN32)|| defined(__CYGWIN__)
+#if defined(_WIN32)|| defined(__CYGWIN__) || defined(__FreeBSD__)
     return (int)(uintptr_t)id;
 #else
     return id;
