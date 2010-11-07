--- usr/sbin/pkcsslotd/mutex.c.orig	2010-07-29 21:28:41.000000000 +0900
+++ usr/sbin/pkcsslotd/mutex.c	2010-10-20 01:19:28.613984045 +0900
@@ -293,6 +293,26 @@
 
 #include "pkcsslotd.h"
 
+#include <fcntl.h>
+
+#ifdef __sun
+#define	LOCK_EX	F_LOCK
+#define	LOCK_UN	F_ULOCK
+#define	flock(fd, func)	lockf(fd, func, 0)
+#endif
+
+#ifndef	LOCK_SH
+#define	LOCK_SH	1	/* shared lock */
+#endif
+#ifndef	LOCK_EX
+#define	LOCK_EX	2	/* exclusive lock */
+#endif
+#ifndef	LOCK_NB
+#define	LOCK_NB	4	/* don't block when locking */
+#endif
+#ifndef	LOCK_UN
+#define	LOCK_UN	8	/* unlock */
+#endif
 
 #if SYSVSEM
 #error "Caveat Emptor... this does not work"
@@ -315,7 +335,6 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
-#include <sys/file.h>
 static int xplfd=-1;
 #endif
 
