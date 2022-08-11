--- usr/lib/api/apiutil.c.orig	2022-04-25 11:04:51 UTC
+++ usr/lib/api/apiutil.c
@@ -19,11 +19,14 @@
 #include <string.h>
 #include <strings.h>
 #include <unistd.h>
+#if !defined(__FreeBSD__)
 #include <alloca.h>
+#endif
 #include <dlfcn.h>
 #include <errno.h>
 #include <sys/syslog.h>
 #include <pthread.h>
+#include <limits.h>
 
 #include <sys/ipc.h>
 
@@ -36,7 +39,6 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
-#include <sys/file.h>
 
 static int xplfd = -1;
 pthread_rwlock_t xplfd_rwlock = PTHREAD_RWLOCK_INITIALIZER;
