--- source/nsswitch/pam_winbind.h.orig	Tue Apr  1 12:57:33 2003
+++ source/nsswitch/pam_winbind.h	Tue Apr  1 12:57:41 2003
@@ -25,7 +25,15 @@
 #define PAM_SM_ACCOUNT
 #define PAM_SM_PASSWORD
 
-#if defined(SUNOS5) || defined(SUNOS4) || defined(HPUX)
+#if (__FreeBSD__ == 0)		/* 1.0 did not define __FreeBSD__ */
+#define __FreeBSD_version 199401
+#elsif __FreeBSD__ == 1		/* 1.1 defined it to be 1 */
+#define __FreeBSD_version 199405
+#else				/* 2.0 and higher define it to be 2 */
+#include <osreldate.h>		/* and this works */
+#endif
+
+#if defined(SUNOS5) || defined(SUNOS4) || defined(HPUX) || (defined (__FreeBSD_version) && (__FreeBSD_version > 500030))
 
 /* Solaris always uses dynamic pam modules */
 #define PAM_EXTERN extern
