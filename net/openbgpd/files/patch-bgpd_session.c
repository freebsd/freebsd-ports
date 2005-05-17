--- bgpd/session.c.orig	Thu Sep  9 23:53:57 2004
+++ bgpd/session.c	Sun Mar 20 15:33:51 2005
@@ -206,9 +206,12 @@
 	setproctitle("session engine");
 	bgpd_process = PROC_SE;
 
+/* we don't have PF_KEY implemented in a way OpenBSD has
+
 	if (pfkey_init(&sysdep) == -1)
 		fatalx("pfkey setup failed");
 
+*/
 	if (setgroups(1, &pw->pw_gid) ||
 	    setegid(pw->pw_gid) || setgid(pw->pw_gid) ||
 	    seteuid(pw->pw_uid) || setuid(pw->pw_uid))
