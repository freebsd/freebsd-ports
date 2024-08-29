--- misc.c.orig	2024-03-26 16:41:57.000000000 -0700
+++ misc.c	2024-04-03 11:32:35.844473000 -0700
@@ -32,8 +32,10 @@
 
 #include <poll.h>
 #include <sys/types.h>
+#include <sys/user.h>
 #include <sys/stat.h>		/* mkdir() declaration */
 #include <signal.h>
+#include <libutil.h>
 #include <stdint.h>
 #include <string.h>
 #include <stdbool.h>
@@ -225,6 +227,7 @@
 	char *p;
 
 	if (str == NULL) {
+
 		*buf = 0;
 		return 0;
 	}
@@ -238,3 +241,17 @@
 	*p = 0;
 	return p - buf;
 }
+
+time_t
+SessionCreationTime(fifo)
+const char *fifo;
+{
+  int pid = atoi(fifo);
+  if (pid <= 0) return 0;
+
+  struct kinfo_proc * kip = kinfo_getproc(pid);
+  if (kip == 0) return 0;
+  time_t start = kip->ki_start.tv_sec;
+  free (kip);
+  return start;
+}
