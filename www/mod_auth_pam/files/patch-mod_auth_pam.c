--- mod_auth_pam.c.orig	Thu Aug  8 13:47:33 2002
+++ mod_auth_pam.c	Thu Jun  3 11:40:47 2004
@@ -147,7 +147,7 @@
 #define PAM_STRE_NEEDS_PAMH 1
 #define VERSION "1.1.1"
 
-module pam_auth_module;
+module auth_pam_module;
 
 static const char
 *pam_servicename = "httpd",
@@ -231,13 +231,11 @@
 
 static command_rec auth_pam_cmds[] = {
   { "AuthFailDelay", (const char*(*)())auth_fail_delay, 0, OR_AUTHCFG, TAKE1,
-    "number of micro seconds to wait after failed authentication attempt. defau
-lt is 0" },
+    "number of micro seconds to wait after failed authentication attempt. default is 0" },
   { "AuthPAM_Authorative", (const char*(*)())auth_fall_through, NULL, OR_AUTHCFG, FLAG,
     "no longer in use -- see AuthPAM_FallThrough instead" },
   { "AuthPAM_FallThrough", (const char*(*)())auth_fall_through, NULL, OR_AUTHCFG, FLAG,
-    "on|off - determines if other authentication methods are attempted if this
-one fails; default is off" },
+    "on|off - determines if other authentication methods are attempted if this one fails; default is off" },
   { "AuthPAM_Enabled", (const char*(*)())auth_enable, NULL, OR_AUTHCFG, FLAG,
     "on|off - determines if PAM authentication is enabled; default is on" },
   { 0 }
@@ -323,7 +321,7 @@
   /* mod_auth_pam specific */
   auth_pam_userinfo userinfo = { NULL, NULL };
   auth_pam_dir_config *conf = (auth_pam_dir_config*)
-    ap_get_module_config(r->per_dir_config, &pam_auth_module);
+    ap_get_module_config(r->per_dir_config, &auth_pam_module);
   /* PAM specific  */
   struct pam_conv conv_info = { &auth_pam_talker, (void*)&userinfo};
   pam_handle_t *pamh  = NULL;
@@ -402,7 +400,7 @@
   register int i = 0;
   char method_restricted = 0, *line = 0, *word = 0;
   auth_pam_dir_config *conf = (auth_pam_dir_config*)
-    ap_get_module_config(r->per_dir_config, &pam_auth_module);
+    ap_get_module_config(r->per_dir_config, &auth_pam_module);
   struct passwd *pwent;
 
   /* check for allowed users/group */
@@ -487,7 +485,7 @@
   return AUTH_REQUIRED;
 }
 
-module pam_auth_module = {
+module auth_pam_module = {
   STANDARD_MODULE_STUFF,
   auth_pam_init,                        /* initializer */
   create_auth_pam_dir_config,  /* dir config creater */
