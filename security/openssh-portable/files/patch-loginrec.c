--- loginrec.c.orig	2010-04-09 02:13:27.000000000 -0600
+++ loginrec.c	2010-09-14 16:14:12.000000000 -0600
@@ -179,6 +179,9 @@
 #ifdef HAVE_UTIL_H
 # include <util.h>
 #endif
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif
 
 #ifdef HAVE_LIBUTIL_H
 # include <libutil.h>
@@ -693,8 +696,13 @@
 	strncpy(ut->ut_name, li->username,
 	    MIN_SIZEOF(ut->ut_name, li->username));
 # ifdef HAVE_HOST_IN_UTMP
+# if defined(__FreeBSD__) && __FreeBSD_version < 400000
 	strncpy(ut->ut_host, li->hostname,
 	    MIN_SIZEOF(ut->ut_host, li->hostname));
+# else
+	realhostname_sa(ut->ut_host, sizeof ut->ut_host,
+	    &li->hostaddr.sa, li->hostaddr.sa.sa_len);
+# endif
 # endif
 # ifdef HAVE_ADDR_IN_UTMP
 	/* this is just a 32-bit IP address */
