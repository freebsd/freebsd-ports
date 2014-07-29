--- config.h.orig	Tue Sep 11 08:53:50 2001
+++ config.h	Sun Mar 30 20:23:47 2003
@@ -52,7 +52,7 @@
 	is group writable or contained in a group writable home directory
 	if the group involved is the user's default group. */
 
-/*#define LMTP					/* uncomment this if you
+#define LMTP                                  /* uncomment this if you
 						   want to use procmail
 	as an LMTP (rfc2033) server, presumably for invocation by an MTA.
 	The file examples/local_procmail_lmtp.m4 contains info on how to
@@ -75,9 +75,9 @@
    >From_ field will be added in the header */
 
 #define TRUSTED_IDS	{"root","daemon","uucp","mail","x400","network",\
-			 "list","slist","lists","news",0}
+			 "list","slist","lists","news","mailnull","majordom","majordomo",0}
 
-/*#define NO_fcntl_LOCK		/* uncomment any of these three if you	     */
+#define NO_fcntl_LOCK         /* uncomment any of these three if you       */
 /*#define NO_lockf_LOCK		/* definitely do not want procmail to make   */
 /*#define NO_flock_LOCK		/* use of those kernel-locking methods	     */
 				/* If you set LOCKINGTEST to a binary number
@@ -116,11 +116,11 @@
 	is not found, maildelivery will proceed as normal to the default
 	system mailbox.	 This also must be an absolute path */
 
-#define ETCRC	"/etc/procmailrc"	/* optional global procmailrc startup
+#define ETCRC   "%%PREFIX%%/etc/procmailrc"       /* optional global procmailrc startup
 					   file (will only be read if procmail
 	is started with no rcfile on the command line). */
 
-#define ETCRCS	"/etc/procmailrcs/"	/* optional trusted path prefix for
+#define ETCRCS  "%%PREFIX%%/etc/procmailrcs/"     /* optional trusted path prefix for
 					   rcfiles which will be executed with
 	the uid of the owner of the rcfile (this only happens if procmail is
 	called with the -m option, without variable assignments on the command
