--- ssh-agent.c.orig	Fri Sep  1 02:38:37 2006
+++ ssh-agent.c	Sat Sep 30 18:30:32 2006
@@ -1036,6 +1036,7 @@
 	/* drop */
 	setegid(getgid());
 	setgid(getgid());
+	setuid(geteuid());
 
 #if defined(HAVE_PRCTL) && defined(PR_SET_DUMPABLE)
 	/* Disable ptrace on Linux without sgid bit */
