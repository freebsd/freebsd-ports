diff --git sesman/verify_user_pam.c sesman/verify_user_pam.c
index e3d8596..281e297 100644
--- sesman/verify_user_pam.c
+++ sesman/verify_user_pam.c
@@ -117,6 +117,14 @@ auth_userpass(char* user, char* pass)
     g_free(auth_info);
     return 0;
   }
+
+  error = pam_set_item(auth_info->ph, PAM_TTY, service_name);
+  if (error != PAM_SUCCESS)
+  {
+    g_printf("pam_set_item failed: %s\r\n",
+                         pam_strerror(auth_info->ph, error));
+  }
+
   error = pam_authenticate(auth_info->ph, 0);
   if (error != PAM_SUCCESS)
   {
