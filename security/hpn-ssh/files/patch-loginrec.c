--- loginrec.c.orig	Tue Apr 23 15:09:19 2002
+++ loginrec.c	Mon Jul 15 21:29:20 2002
@@ -654,7 +655,8 @@
 	/* Use strncpy because we don't necessarily want null termination */
 	strncpy(ut->ut_name, li->username, MIN_SIZEOF(ut->ut_name, li->username));
 # ifdef HAVE_HOST_IN_UTMP
-	strncpy(ut->ut_host, li->hostname, MIN_SIZEOF(ut->ut_host, li->hostname));
+	realhostname_sa(ut->ut_host, sizeof ut->ut_host,
+	    &li->hostaddr.sa, li->hostaddr.sa.sa_len);
 # endif
 # ifdef HAVE_ADDR_IN_UTMP
 	/* this is just a 32-bit IP address */
