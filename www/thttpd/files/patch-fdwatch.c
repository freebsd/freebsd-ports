--- fdwatch.c.orig	Tue Apr 24 18:40:22 2001
+++ fdwatch.c	Tue Apr 24 19:00:57 2001
@@ -32,6 +32,7 @@
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <syslog.h>
+#include <sys/param.h>
 
 #ifndef MIN
 #define MIN(a,b) ((a) < (b) ? (a) : (b))
@@ -44,6 +45,10 @@
 #include <sys/poll.h>
 #endif /* HAVE_SYS_POLL_H */
 #endif /* HAVE_POLL_H */
+
+#ifdef HAVE_FREEBSD_CURRENT
+#undef HAVE_KQUEUE
+#endif
 
 #ifdef HAVE_SYS_EVENT_H
 #include <sys/event.h>
