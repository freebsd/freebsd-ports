--- ./ClamAV.pm.orig	2009-04-30 01:02:43.000000000 +0200
+++ ./ClamAV.pm	2014-03-02 11:45:39.000000000 +0100
@@ -286,7 +286,7 @@
     reclevel = cl_engine_get_num(c->root, CL_ENGINE_MAX_RECURSION, &err);
     if (err != CL_SUCCESS) {
         error(err);
-        return;
+        return 0;
     }
     return reclevel;
 }
@@ -313,7 +313,7 @@
     maxfiles = cl_engine_get_num(c->root, CL_ENGINE_MAX_FILES, &err);
     if (err != CL_SUCCESS) {
         error(err);
-        return;
+        return 0;
     }
     return maxfiles;
 }
@@ -334,7 +334,7 @@
     maxfsize = cl_engine_get_num(c->root, CL_ENGINE_MAX_FILESIZE, &err);
     if (err != CL_SUCCESS) {
         error(err);
-        return;
+        return 0;
     }
     return maxfsize;
 }
