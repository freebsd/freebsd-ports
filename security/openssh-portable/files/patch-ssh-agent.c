--- ssh-agent.c.orig	2010-04-15 23:56:22.000000000 -0600
+++ ssh-agent.c	2010-09-14 16:14:13.000000000 -0600
@@ -1086,6 +1086,7 @@
 	/* drop */
 	setegid(getgid());
 	setgid(getgid());
+	setuid(geteuid());
 
 #if defined(HAVE_PRCTL) && defined(PR_SET_DUMPABLE)
 	/* Disable ptrace on Linux without sgid bit */
