--- auth-pam.h	Tue Jul 23 02:44:07 2002
+++ cvs-current/auth-pam.h	Sat Dec 14 14:52:39 2002
@@ -37,8 +38,8 @@
 char **fetch_pam_environment(void);
 void free_pam_environment(char **env);
 int do_pam_authenticate(int flags);
-int do_pam_account(char *username, char *remote_user);
-void do_pam_session(char *username, const char *ttyname);
+int do_pam_account(const char *username, const char *remote_user);
+void do_pam_session(const char *username, const char *ttyname);
 void do_pam_setcred(int init);
 void print_pam_messages(void);
 int is_pam_password_change_required(void);
