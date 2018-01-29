--- src/function.c	2018-01-04 20:59:38 UTC
+++ src/function.c
@@ -8,7 +8,9 @@
 #include <dirent.h>
 #include <sys/statvfs.h>
 #include <sys/types.h>
+#ifdef __linux__
 #include <attr/xattr.h>
+#endif
 #include <time.h>
 #include <pthread.h>
 #include <libsmbclient.h>
