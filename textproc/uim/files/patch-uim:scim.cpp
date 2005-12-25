--- uim/scim.cpp.orig	Wed Dec  7 21:39:32 2005
+++ uim/scim.cpp	Sat Dec 24 04:13:02 2005
@@ -43,7 +43,6 @@
 #include "uim.h"
 #include "uim-scm.h"
 #include "uim-compat-scm.h"
-#include "context.h"
 
 using namespace scim;
 
@@ -175,7 +174,7 @@
             return uim_scm_f();
         }
 
-        config = config_module->create_config("scim");
+        config = config_module->create_config();
         if ( config.null() )
         {
             fprintf(stderr, "create_config failed\n");
