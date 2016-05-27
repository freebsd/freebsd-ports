--- usr/sbin/pkcsslotd/mutex.c.orig	2016-04-29 17:26:46 UTC
+++ usr/sbin/pkcsslotd/mutex.c
@@ -281,10 +281,28 @@
              legal action under this Agreement more than one year after
              the cause of action arose. Each party waives its rights to
              a jury trial in any resulting litigation. 
+*/
 
+#include <fcntl.h>
 
+#ifdef __sun
+#define	LOCK_EX	F_LOCK
+#define	LOCK_UN	F_ULOCK
+#define	flock(fd, func)	lockf(fd, func, 0)
+#endif
 
-*/
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
 
 /* (C) COPYRIGHT International Business Machines Corp. 2001          */
 
@@ -323,7 +341,7 @@ CreateXProcLock(void)
 					goto error;
 				}
 
-				grp = getgrnam("pkcs11");
+				grp = getgrnam(PKCS11GROUP);
 				if (grp != NULL) {
 					if (fchown(xplfd,-1,grp->gr_gid) == -1) {
 						DbgLog(DL0,"%s:fchown(%s):%s\n",
