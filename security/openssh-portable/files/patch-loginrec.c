--- loginrec.c.orig	Tue Feb 15 12:19:28 2005
+++ loginrec.c	Sat Mar 19 20:55:59 2005
@@ -164,6 +164,9 @@
 #ifdef HAVE_LIBUTIL_H
 # include <libutil.h>
 #endif
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif
 
 RCSID("$Id: loginrec.c,v 1.67 2005/02/15 11:19:28 dtucker Exp $");
 
@@ -670,8 +673,13 @@
 	strncpy(ut->ut_name, li->username,
 	    MIN_SIZEOF(ut->ut_name, li->username));
 # ifdef HAVE_HOST_IN_UTMP
+# if defined(__FreeBSD__) && __FreeBSD_version <= 400000
 	strncpy(ut->ut_host, li->hostname,
 	    MIN_SIZEOF(ut->ut_host, li->hostname));
+# else
+	realhostname_sa(ut->ut_host, sizeof ut->ut_host,
+	    &li->hostaddr.sa, li->hostaddr.sa.sa_len);
+# endif
 # endif
 # ifdef HAVE_ADDR_IN_UTMP
 	/* this is just a 32-bit IP address */
