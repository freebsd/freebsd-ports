--- misc.c.orig	2022-01-28 14:06:02 UTC
+++ misc.c
@@ -28,8 +28,10 @@
 
 #include <poll.h>
 #include <sys/types.h>
+#include <sys/user.h>
 #include <sys/stat.h>	/* mkdir() declaration */
 #include <signal.h>
+#include <libutil.h>
 
 #include "config.h"
 #include "screen.h"
@@ -796,3 +798,17 @@
 }
 
 #endif
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
