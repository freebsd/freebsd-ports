--- pathnames.h.orig	Thu Jul 11 21:52:45 2002
+++ pathnames.h	Mon Jul 22 07:19:30 2002
@@ -12,7 +12,7 @@
  * called by a name other than "ssh" or "Secure Shell".
  */
 
-#define ETCDIR				"/etc"
+#define ETCDIR				"__PREFIX__/etc/ssh"
 #define SSHDIR				ETCDIR
 #define _PATH_SSH_PIDDIR		"/var/run"
 
@@ -37,7 +37,7 @@
 /* Backwards compatibility */
 #define _PATH_DH_PRIMES			ETCDIR "/primes"
 
-#define _PATH_SSH_PROGRAM		"/usr/bin/ssh"
+#define _PATH_SSH_PROGRAM		"__PREFIX__/bin/ssh"
 
 /*
  * The process id of the daemon listening for connections is saved here to
@@ -120,11 +120,13 @@
 #define _PATH_UNIX_X "/tmp/.X11-unix/X%u"
 
 /* for scp */
+#ifndef _PATH_CP
 #define _PATH_CP			"cp"
+#endif
 
 /* for sftp */
-#define _PATH_SFTP_SERVER		"/usr/libexec/sftp-server"
+#define _PATH_SFTP_SERVER		"__PREFIX__/libexec/sftp-server"
 #define _PATH_LS			"ls"
 
 /* chroot directory for unprivileged user when UsePrivilegeSeparation=yes */
-#define _PATH_PRIVSEP_CHROOT_DIR	"/var/empty"
+#define _PATH_PRIVSEP_CHROOT_DIR	"__PREFIX__/empty"
