--- usr/lib/pkcs11/api/apiutil.c.orig	2010-07-29 21:28:41.000000000 +0900
+++ usr/lib/pkcs11/api/apiutil.c	2010-10-19 23:54:52.374982634 +0900
@@ -305,10 +305,10 @@
 #include <string.h>
 #include <strings.h>
 #include <unistd.h>
-#include <alloca.h>
 #include <dlfcn.h>
 #include <errno.h>
 #include <sys/syslog.h>
+#include <limits.h>
 
 #include <sys/ipc.h>
 
@@ -325,10 +325,28 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
-#include <sys/file.h>
 static int xplfd=-1;
 #endif
 
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
+
 #include <libgen.h>
 
 #define LIBLOCATION  LIB_PATH
