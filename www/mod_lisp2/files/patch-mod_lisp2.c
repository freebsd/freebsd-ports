--- mod_lisp2.c.orig	2008-06-17 17:51:40.000000000 +0200
+++ mod_lisp2.c	2008-06-17 17:53:20.000000000 +0200
@@ -153,7 +153,7 @@
 #include <stdlib.h>
 #include <string.h>
 
-module AP_MODULE_DECLARE_DATA lisp_module;
+module AP_MODULE_DECLARE_DATA lisp2_module;
 /* Work out the version of the apache portable runtime (APR) we're
  * compiling against... with version 1.2.2 some of the interfaces
  * changed a bit. */
@@ -576,7 +576,7 @@
 lisp_handler (request_rec * r)
 {
   lisp_cfg_t * cfg
-    = (ap_get_module_config ((r->per_dir_config), (&lisp_module)));
+    = (ap_get_module_config ((r->per_dir_config), (&lisp2_module)));
   int content_length = (-1);
   int keep_socket_p = 0;
   apr_socket_t * socket;
@@ -942,7 +942,7 @@
   ap_hook_handler (lisp_handler, 0, 0, APR_HOOK_MIDDLE);
 }
 
-module AP_MODULE_DECLARE_DATA lisp_module =
+module AP_MODULE_DECLARE_DATA lisp2_module =
 {
   STANDARD20_MODULE_STUFF,
   lisp_create_dir_config,	/* create per-directory config structures */
