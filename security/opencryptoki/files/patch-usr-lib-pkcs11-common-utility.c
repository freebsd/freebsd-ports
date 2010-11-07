--- usr/lib/pkcs11/common/utility.c.orig	2010-07-29 21:28:41.000000000 +0900
+++ usr/lib/pkcs11/common/utility.c	2010-10-20 00:19:02.740983592 +0900
@@ -302,6 +302,26 @@
 #include <errno.h>
 #include <pwd.h>
 
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
 
 #include "pkcs11types.h"
 #include "defs.h"
