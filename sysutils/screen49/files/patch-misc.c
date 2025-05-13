--- misc.c.orig	2023-08-16 00:29:26 UTC
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
@@ -720,3 +722,17 @@ xvsnprintf(char *s, int n, char *fmt, xva_list stack)
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
