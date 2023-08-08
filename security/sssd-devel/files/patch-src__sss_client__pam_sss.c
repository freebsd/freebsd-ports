--- src/sss_client/pam_sss.c.orig	2023-05-05 08:11:07 UTC
+++ src/sss_client/pam_sss.c
@@ -1422,7 +1422,7 @@ static int get_pam_items(pam_handle_t *pamh, uint32_t 
 
     pi->cli_pid = getpid();
 
-    pi->login_name = pam_modutil_getlogin(pamh);
+    pi->login_name = getlogin();
     if (pi->login_name == NULL) pi->login_name="";
 
     pi->domain_name = NULL;
