--- src/apache2/mod_suphp.c.orig	2006-11-05 16:57:12.000000000 -0800
+++ src/apache2/mod_suphp.c	2007-11-11 03:15:50.000000000 -0800
@@ -321,8 +321,8 @@
     AP_INIT_TAKE2("suPHP_UserGroup", suphp_handle_cmd_user_group, NULL, RSRC_CONF | ACCESS_CONF,
                   "User and group scripts shall be run as"),
 #endif
-    AP_INIT_ITERATE("suPHP_AddHandler", suphp_handle_cmd_add_handler, NULL, ACCESS_CONF, "Tells mod_suphp to handle these MIME-types"),
-    AP_INIT_ITERATE("suPHP_RemoveHandler", suphp_handle_cmd_remove_handler, NULL, ACCESS_CONF, "Tells mod_suphp not to handle these MIME-types"),
+    AP_INIT_ITERATE("suPHP_AddHandler", suphp_handle_cmd_add_handler, NULL, RSRC_CONF | ACCESS_CONF, "Tells mod_suphp to handle these MIME-types"),
+    AP_INIT_ITERATE("suPHP_RemoveHandler", suphp_handle_cmd_remove_handler, NULL, RSRC_CONF | ACCESS_CONF, "Tells mod_suphp not to handle these MIME-types"),
     {NULL}
 };
 
