--- admin/get.c.orig	Sun Oct 28 18:41:42 2001
+++ admin/get.c	Sun Oct 28 18:43:13 2001
@@ -41,8 +41,8 @@
 		       char *admin_server, 
 		       int server_port)
 {
+    static kadm5_config_params conf;
     krb5_error_code ret;
-    kadm5_config_params conf;
     void *kadm_handle;
     memset(&conf, 0, sizeof(conf));
 
