--- loginrec.c.orig	Sun Aug 15 11:12:52 2004
+++ loginrec.c	Mon Sep 20 05:04:48 2004
@@ -167,6 +167,9 @@
 #ifdef HAVE_LIBUTIL_H
 #   include <libutil.h>
 #endif
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif
 
 /**
  ** prototypes for helper functions in this file
@@ -657,7 +660,12 @@
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
