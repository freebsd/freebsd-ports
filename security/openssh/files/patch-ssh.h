--- ssh.h.orig	Fri Jun 28 06:15:27 2002
+++ ssh.h	Fri Jun 28 06:16:33 2002
@@ -90,7 +90,7 @@
  * sshd will change its privileges to this user and its
  * primary group.
  */
-#define SSH_PRIVSEP_USER		"nobody"
+#define SSH_PRIVSEP_USER		"sshd"
 
 /* Minimum modulus size (n) for RSA keys. */
 #define SSH_RSA_MINIMUM_MODULUS_SIZE	768
