--- uim/scim.cpp.orig	Wed Sep 21 00:27:36 2005
+++ uim/scim.cpp	Wed Sep 21 00:29:33 2005
@@ -175,7 +175,7 @@
             return uim_scm_f();
         }
 
-        config = config_module->create_config("scim");
+        config = config_module->create_config();
         if ( config.null() )
         {
             fprintf(stderr, "create_config failed\n");
