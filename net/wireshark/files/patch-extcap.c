--- extcap.c.orig	2016-09-12 21:16:52 UTC
+++ extcap.c
@@ -33,6 +33,7 @@
 #include <process.h>
 #include <time.h>
 #else
+#include <sys/wait.h>
 /* Include for unlink */
 #include <unistd.h>
 #endif
