--- auth-pam.c.orig	Thu Jan 20 03:29:51 2005
+++ auth-pam.c	Sat Mar 19 21:52:37 2005
@@ -290,7 +290,7 @@
  * Conversation function for authentication thread.
  */
 static int
-sshpam_thread_conv(int n, struct pam_message **msg,
+sshpam_thread_conv(int n, const struct pam_message **msg,
     struct pam_response **resp, void *data)
 {
 	Buffer buffer;
@@ -390,7 +390,7 @@
 	u_int i;
 	const char *pam_user;
 
-	pam_get_item(sshpam_handle, PAM_USER, (void **)&pam_user);
+	pam_get_item(sshpam_handle, PAM_USER, (const void **)&pam_user);
 	environ[0] = NULL;
 
 	if (sshpam_authctxt != NULL) {
@@ -482,7 +482,7 @@
 }
 
 static int
-sshpam_null_conv(int n, struct pam_message **msg,
+sshpam_null_conv(int n, const struct pam_message **msg,
     struct pam_response **resp, void *data)
 {
 	debug3("PAM: %s entering, %d messages", __func__, n);
@@ -492,7 +492,7 @@
 static struct pam_conv null_conv = { sshpam_null_conv, NULL };
 
 static int
-sshpam_store_conv(int n, struct pam_message **msg,
+sshpam_store_conv(int n, const struct pam_message **msg,
     struct pam_response **resp, void *data)
 {
 	struct pam_response *reply;
@@ -565,7 +565,7 @@
 	if (sshpam_handle != NULL) {
 		/* We already have a PAM context; check if the user matches */
 		sshpam_err = pam_get_item(sshpam_handle,
-		    PAM_USER, (void **)&pam_user);
+		    PAM_USER, (const void **)&pam_user);
 		if (sshpam_err == PAM_SUCCESS && strcmp(user, pam_user) == 0)
 			return (0);
 		pam_end(sshpam_handle, sshpam_err);
@@ -881,7 +881,7 @@
 }
 
 static int
-sshpam_tty_conv(int n, struct pam_message **msg,
+sshpam_tty_conv(int n, const struct pam_message **msg,
     struct pam_response **resp, void *data)
 {
 	char input[PAM_MAX_MSG_SIZE];
@@ -1040,7 +1040,7 @@
  * display.
  */
 static int
-sshpam_passwd_conv(int n, struct pam_message **msg,
+sshpam_passwd_conv(int n, const struct pam_message **msg,
     struct pam_response **resp, void *data)
 {
 	struct pam_response *reply;
