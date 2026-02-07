--- ./vortex.c.orig	2011-09-16 15:35:15.000000000 -0400
+++ ./vortex.c	2013-04-18 09:50:33.000000000 -0400
@@ -38,6 +38,12 @@
 
 #ifdef linux
 #include <syscall.h>
+#elif defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/cpuset.h>
+typedef cpuset_t cpu_set_t;
+#include <limits.h>
+#define SIZE_MAX SSIZE_MAX
 #endif
 
 #include <unistd.h>
@@ -65,8 +71,13 @@
 #endif
 
 //don't ask me why this isn't in headers?
-#define gettid() syscall(__NR_gettid)
+#ifdef linux
 #define my_sched_setaffinity(a,b,c) sched_setaffinity(a, b, c)
+#define gettid() syscall(__NR_gettid)
+#elif defined(__FreeBSD__)
+#define my_sched_setaffinity(a,b,c) (-1)
+#define gettid() 0
+#endif
 
 //TODO LIST:
 
