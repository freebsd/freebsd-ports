--- pathnames.h.orig	Sat Jun 22 12:40:30 2002
+++ pathnames.h	Mon Jun 24 23:05:59 2002
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
@@ -123,8 +123,8 @@
 #define _PATH_CP			"cp"
 
 /* for sftp */
-#define _PATH_SFTP_SERVER		"/usr/libexec/sftp-server"
+#define _PATH_SFTP_SERVER		"__PREFIX__/libexec/sftp-server"
 #define _PATH_LS			"ls"
 
 /* chroot directory for unprivileged user when UsePrivilegeSeparation=yes */
-#define _PATH_PRIVSEP_CHROOT_DIR	"/var/empty"
+#define _PATH_PRIVSEP_CHROOT_DIR	"__PREFIX__/empty"
