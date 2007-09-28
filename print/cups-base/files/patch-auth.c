--- scheduler/auth.c.orig	Sat Aug 11 01:09:45 2007
+++ scheduler/auth.c	Thu Aug 16 20:43:41 2007
@@ -84,6 +84,7 @@
 #  endif /* HAVE_SECBASEPRIV_H */
 #endif /* HAVE_AUTHORIZATION_H */
 #ifdef HAVE_SYS_UCRED_H
+#  include <sys/param.h>
 #  include <sys/ucred.h>
 typedef struct xucred cupsd_ucred_t;
 #  define CUPSD_UCRED_UID(c) (c).cr_uid
