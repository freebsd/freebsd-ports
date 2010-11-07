--- usr/lib/pkcs11/tpm_stdll/utility.c.orig	2010-07-29 21:28:41.000000000 +0900
+++ usr/lib/pkcs11/tpm_stdll/utility.c	2010-10-20 00:33:02.810983787 +0900
@@ -44,6 +44,27 @@
 #include "tok_spec_struct.h"
 #include "pkcs32.h"
 
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
+
 #if (SPINXPL)
 #include <sys/file.h>
 #endif
