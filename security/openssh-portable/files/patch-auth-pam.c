--- auth-pam.c.orig	Tue Apr 29 11:12:08 2003
+++ auth-pam.c	Thu Sep 25 22:42:45 2003
@@ -228,7 +228,7 @@
 }
 
 /* Do account management using PAM */
-int do_pam_account(char *username, char *remote_user)
+int old_do_pam_account(const char *username, const char *remote_user)
 {
 	int pam_retval;
 
@@ -271,7 +271,7 @@
 }
 
 /* Do PAM-specific session initialisation */
-void do_pam_session(char *username, const char *ttyname)
+void old_do_pam_session(const char *username, const char *ttyname)
 {
 	int pam_retval;
 
@@ -294,7 +294,7 @@
 }
 
 /* Set PAM credentials */
-void do_pam_setcred(int init)
+void old_do_pam_setcred(int init)
 {
 	int pam_retval;
 
@@ -318,7 +318,7 @@
 }
 
 /* accessor function for file scope static variable */
-int is_pam_password_change_required(void)
+int old_is_pam_password_change_required(void)
 {
 	return password_change_required;
 }
@@ -329,7 +329,7 @@
  * session is established and the user's pty is connected to
  * stdin/stdout/stderr.
  */
-void do_pam_chauthtok(void)
+void old_do_pam_chauthtok(void)
 {
 	int pam_retval;
 
@@ -357,14 +357,14 @@
 }
 
 /* Cleanly shutdown PAM */
-void finish_pam(void)
+void old_finish_pam(void)
 {
 	do_pam_cleanup_proc(NULL);
 	fatal_remove_cleanup(&do_pam_cleanup_proc, NULL);
 }
 
 /* Start PAM authentication for specified account */
-void start_pam(const char *user)
+void old_start_pam(const char *user)
 {
 	int pam_retval;
 	extern ServerOptions options;
@@ -404,7 +404,7 @@
 }
 
 /* Return list of PAM environment strings */
-char **fetch_pam_environment(void)
+char **old_fetch_pam_environment(void)
 {
 #ifdef HAVE_PAM_GETENVLIST
 	return(pam_getenvlist(__pamh));
@@ -413,7 +413,7 @@
 #endif /* HAVE_PAM_GETENVLIST */
 }
 
-void free_pam_environment(char **env)
+void old_free_pam_environment(char **env)
 {
 	int i;
 
@@ -425,7 +425,7 @@
 
 /* Print any messages that have been generated during authentication */
 /* or account checking to stderr */
-void print_pam_messages(void)
+void old_print_pam_messages(void)
 {
 	if (__pam_msg != NULL)
 		fputs(__pam_msg, stderr);
