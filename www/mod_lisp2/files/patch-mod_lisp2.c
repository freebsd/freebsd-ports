--- mod_lisp2.c.orig	2007-07-17 09:11:05.000000000 -0400
+++ mod_lisp2.c	2009-02-13 10:30:48.000000000 -0500
@@ -153,11 +153,11 @@
 #include <stdlib.h>
 #include <string.h>
 
-module AP_MODULE_DECLARE_DATA lisp_module;
+module AP_MODULE_DECLARE_DATA lisp2_module;
 /* Work out the version of the apache portable runtime (APR) we're
  * compiling against... with version 1.2.2 some of the interfaces
  * changed a bit. */
-#if (APR_MAJOR_VERSION==1 && APR_MINOR_VERSION==2 && APR_PATCH_VERSION>=2)
+#if (APR_MAJOR_VERSION==1 && ((APR_MINOR_VERSION==2 && APR_PATCH_VERSION>=2) || APR_MINOR_VERSION>=3))
 #define HAVE_APR_1_2_2    1
 #endif
 
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
