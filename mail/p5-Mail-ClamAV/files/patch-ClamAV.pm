--- ClamAV.pm.orig	2009-04-29 23:02:43 UTC
+++ ClamAV.pm
@@ -286,7 +286,7 @@ int clamav_perl_maxreclevel(SV *self, ...)
     reclevel = cl_engine_get_num(c->root, CL_ENGINE_MAX_RECURSION, &err);
     if (err != CL_SUCCESS) {
         error(err);
-        return;
+        return 0;
     }
     return reclevel;
 }
@@ -313,7 +313,7 @@ int clamav_perl_maxfiles(SV *self, ...)
     maxfiles = cl_engine_get_num(c->root, CL_ENGINE_MAX_FILES, &err);
     if (err != CL_SUCCESS) {
         error(err);
-        return;
+        return 0;
     }
     return maxfiles;
 }
@@ -334,7 +334,7 @@ int clamav_perl_maxfilesize(SV *self, ...)
     maxfsize = cl_engine_get_num(c->root, CL_ENGINE_MAX_FILESIZE, &err);
     if (err != CL_SUCCESS) {
         error(err);
-        return;
+        return 0;
     }
     return maxfsize;
 }
