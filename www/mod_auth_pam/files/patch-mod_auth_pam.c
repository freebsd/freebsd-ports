--- mod_auth_pam.c.orig	Sun Feb 13 23:16:57 2000
+++ mod_auth_pam.c	Mon Apr  2 22:20:44 2001
@@ -113,7 +113,7 @@
 #define PAM_STRE_NEEDS_PAMH 1
 #define VERSION "1.0a"
 
-module pam_auth_module;
+module auth_pam_module;
 
 static const char
 *pam_servicename = "httpd",
@@ -362,7 +362,7 @@
   /* mod_auth_pam specific */
   auth_pam_userinfo userinfo = { NULL, NULL };
   auth_pam_dir_config *conf = (auth_pam_dir_config*)
-    ap_get_module_config(r->per_dir_config, &pam_auth_module);
+    ap_get_module_config(r->per_dir_config, &auth_pam_module);
   /* PAM specific  */
   struct pam_conv conv_info = { &auth_pam_talker, (void*)&userinfo};
   pam_handle_t *pamh  = NULL;
@@ -442,7 +442,7 @@
   char method_restricted = 0, *line = 0, *word = 0;
   table *groups = 0;
   auth_pam_dir_config *conf = (auth_pam_dir_config*)
-    ap_get_module_config(r->per_dir_config, &pam_auth_module);
+    ap_get_module_config(r->per_dir_config, &auth_pam_module);
 
   /* check for allowed users/group */
   const array_header *reqs_arr = ap_requires (r);
@@ -505,7 +505,7 @@
   return AUTH_REQUIRED;
 }
 
-module pam_auth_module = {
+module auth_pam_module = {
   STANDARD_MODULE_STUFF,
   auth_pam_init,                        /* initializer */
   create_auth_pam_dir_config,  /* dir config creater */
