--- /home/bright/ssh/ssh/sshd.c	Thu Aug 17 13:06:34 2000
+++ sshd.c	Fri Feb  9 11:19:08 2001
@@ -49,6 +49,12 @@
 int deny_severity = LOG_WARNING;
 #endif /* LIBWRAP */
 
+#ifdef __FreeBSD__
+#include <libutil.h>
+#include <syslog.h>
+#include <time.h>
+#endif /* __FreeBSD__ */
+
 #ifndef O_NOCTTY
 #define O_NOCTTY	0
 #endif
