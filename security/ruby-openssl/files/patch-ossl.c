--- ossl.c.orig	Tue Jul 23 23:24:54 2002
+++ ossl.c	Wed Jul 24 20:30:59 2002
@@ -26,6 +26,17 @@
 #  include <time.h>
 #endif
 
+#ifdef HAVE_SYS_TIME_H
+#  include <sys/time.h>
+#else
+#ifndef NT
+struct timeval {
+	long	tv_sec;		/* seconds */
+	long	tv_usec;	/* and microseconds */
+};
+#endif /* NT */
+#endif
+
 /*
  * Check Types
  */
