--- pathnames.h.orig	Fri Mar  8 05:51:08 2002
+++ pathnames.h	Fri Mar  8 05:52:57 2002
@@ -12,7 +12,7 @@
  * called by a name other than "ssh" or "Secure Shell".
  */
 
-#define ETCDIR				"/etc"
+#define ETCDIR				"__PREFIX__/etc"
 #define SSHDIR				ETCDIR
 #define _PATH_SSH_PIDDIR		"/var/run"
 
@@ -37,7 +37,7 @@
 /* Backwards compatibility */
 #define _PATH_DH_PRIMES			ETCDIR "/primes"
 
-#define _PATH_SSH_PROGRAM		"/usr/bin/ssh"
+#define _PATH_SSH_PROGRAM		"__PREFIX__/bin/ssh"
 
 /*
  * The process id of the daemon listening for connections is saved here to
