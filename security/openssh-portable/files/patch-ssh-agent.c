r110506 | des | 2003-02-07 09:48:27 -0600 (Fri, 07 Feb 2003) | 4 lines

Set the ruid to the euid at startup as a workaround for a bug in pam_ssh.

--- ssh-agent.c.orig	2010-04-15 23:56:22.000000000 -0600
+++ ssh-agent.c	2010-09-14 16:14:13.000000000 -0600
@@ -1086,6 +1086,7 @@
 	/* drop */
 	setegid(getgid());
 	setgid(getgid());
+	setuid(geteuid());
 
 #if defined(HAVE_PRCTL) && defined(PR_SET_DUMPABLE)
 	/* Disable ptrace on Linux without sgid bit */
