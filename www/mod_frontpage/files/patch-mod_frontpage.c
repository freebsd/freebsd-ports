--- mod_frontpage.c.orig	Sun Dec  9 23:48:35 2001
+++ mod_frontpage.c	Mon Jan 21 13:02:01 2002
@@ -110,7 +110,7 @@
 
 static void init (server_rec* s, pool* p)
 {
-    ap_add_version_component ("FrontPage/5.0.2.2510");
+    ap_add_version_component ("FrontPage/5.0.2.2623");
     while (s != NULL) {
         conf* c = ap_get_module_config (s->module_config, &frontpage_module);
         if (c->disabled == -1)
