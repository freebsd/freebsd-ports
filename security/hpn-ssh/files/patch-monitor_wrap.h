--- monitor_wrap.h.orig	Mon May 13 03:07:42 2002
+++ monitor_wrap.h	Sun Jun 30 07:13:18 2002
@@ -57,6 +58,10 @@
 
 #ifdef USE_PAM
 void mm_start_pam(char *);
+void *mm_pam_init_ctx(struct Authctxt *);
+int mm_pam_query(void *, char **, char **, u_int *, char ***, u_int **);
+int mm_pam_respond(void *, u_int, char **);
+void mm_pam_free_ctx(void *);
 #endif
 
 void mm_terminate(void);
