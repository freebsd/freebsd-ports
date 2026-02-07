--- params.h.orig	Tue Oct 16 06:10:34 2001
+++ params.h	Sat Dec 22 11:57:52 2001
@@ -99,7 +99,7 @@
  * A pseudo-user to run as before authentication. The user and its UID
  * must not be used for any other purpose.
  */
-#define POP_USER			POP_SERVER
+#define POP_USER			"pop"
 
 /*
  * An empty directory to chroot to before authentication. The directory
@@ -142,8 +142,8 @@
  *
  * Note that there's no built-in password aging support.
  */
-#define AUTH_PASSWD			0
-#define AUTH_SHADOW			1
+#define AUTH_PASSWD			1
+#define AUTH_SHADOW			0
 #define AUTH_PAM			0
 #define AUTH_PAM_USERPASS		0
 
