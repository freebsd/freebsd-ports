--- loginrec.c.orig	Tue Apr 23 15:09:19 2002
+++ loginrec.c	Wed Jul 24 08:13:44 2002
@@ -171,6 +171,7 @@
 
 #ifdef HAVE_LIBUTIL_H
 #   include <libutil.h>
+#   include <osreldate.h>
 #endif
 
 /**
@@ -654,7 +655,12 @@
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
