--- loginrec.c.orig	Thu Sep 26 02:38:49 2002
+++ loginrec.c	Mon Oct 21 06:51:34 2002
@@ -172,6 +172,9 @@
 #ifdef HAVE_LIBUTIL_H
 #   include <libutil.h>
 #endif
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif
 
 /**
  ** prototypes for helper functions in this file
@@ -654,7 +657,12 @@
 	/* Use strncpy because we don't necessarily want null termination */
 	strncpy(ut->ut_name, li->username, MIN_SIZEOF(ut->ut_name, li->username));
 # ifdef HAVE_HOST_IN_UTMP
+# if defined(__FreeBSD__) && __FreeBSD_version <= 400000
 	strncpy(ut->ut_host, li->hostname, MIN_SIZEOF(ut->ut_host, li->hostname));
+# else
+	realhostname_sa(ut->ut_host, sizeof ut->ut_host,
+	    &li->hostaddr.sa, li->hostaddr.sa.sa_len);
+# endif
 # endif
 # ifdef HAVE_ADDR_IN_UTMP
 	/* this is just a 32-bit IP address */
