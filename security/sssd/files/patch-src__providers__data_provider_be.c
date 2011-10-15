--- ./src/providers/data_provider_be.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/providers/data_provider_be.c	2011-10-13 12:15:03.000000000 -0400
@@ -512,7 +512,7 @@
         return EIO;
     }
 
-    pd->pam_status = PAM_SYSTEM_ERR;
+    pd->pam_status = PAM_SERVICE_ERR;
     pd->domain = talloc_strdup(pd, becli->bectx->domain->name);
     if (pd->domain == NULL) {
         talloc_free(be_req);
@@ -1013,7 +1013,7 @@
         if (!handle) {
             DEBUG(0, ("Unable to load %s module with path (%s), error: %s\n",
                       mod_name, path, dlerror()));
-            ret = ELIBACC;
+            ret = ENOENT;
             goto done;
         }
 
@@ -1033,7 +1033,7 @@
         } else {
             DEBUG(0, ("Unable to load init fn %s from module %s, error: %s\n",
                       mod_init_fn_name, mod_name, dlerror()));
-            ret = ELIBBAD;
+            ret = ENOENT;
         }
         goto done;
     }
