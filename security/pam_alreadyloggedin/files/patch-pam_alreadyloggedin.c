--- pam_alreadyloggedin.c.orig	Tue Sep 21 17:41:20 2004
+++ pam_alreadyloggedin.c	Thu Dec 23 00:58:02 2004
@@ -70,6 +70,11 @@
 int inutmp(struct utmp *utmp, const char *lineglob, const char *username,
     uid_t uid);
 
+#ifdef PAM_MAX_OPTIONS
+/* The old PAM requires this structure. */
+static struct options options;
+#endif
+
 PAM_EXTERN int
 pam_sm_authenticate(pam_handle_t *pamh, int flags __unused, int argc,
     const char **argv)
