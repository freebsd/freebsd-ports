r63028 | dinoex | 2002-07-15 15:08:01 -0500 (Mon, 15 Jul 2002) | 6 lines

- Fix Problem with HAVE_HOST_IN_UTMP
- update monitor.c

PR:             40576
Submitted by:   lxv@a-send-pr.sink.omut.org

r99768 | des | 2002-07-11 05:36:10 -0500 (Thu, 11 Jul 2002) | 6 lines

Use realhostname_sa(3) so the IP address will be used instead of the
hostname if the latter is too long for utmp.

Submitted by:   ru

--- loginrec.c.orig	2013-04-14 08:28:40.482762815 -0500
+++ loginrec.c	2013-04-14 08:29:03.723757797 -0500
@@ -694,8 +694,8 @@
 	strncpy(ut->ut_name, li->username,
 	    MIN_SIZEOF(ut->ut_name, li->username));
 # ifdef HAVE_HOST_IN_UTMP
-	strncpy(ut->ut_host, li->hostname,
-	    MIN_SIZEOF(ut->ut_host, li->hostname));
+	realhostname_sa(ut->ut_host, sizeof ut->ut_host,
+	    &li->hostaddr.sa, li->hostaddr.sa.sa_len);
 # endif
 # ifdef HAVE_ADDR_IN_UTMP
 	/* this is just a 32-bit IP address */
