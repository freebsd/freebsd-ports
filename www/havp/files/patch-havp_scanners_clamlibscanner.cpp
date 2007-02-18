--- havp/scanners/clamlibscanner.cpp.orig	Sun Feb 18 15:32:07 2007
+++ havp/scanners/clamlibscanner.cpp	Sun Feb 18 15:32:35 2007
@@ -29,7 +29,7 @@
 
     LogFile::ErrorMessage("ClamAV: Using database directory: %s\n", dbdir);
 
-    if ( (ret = cl_loaddbdir(dbdir, &root, &no)) != 0 )
+    if ( (ret = cl_load(dbdir, &root, &no, CL_DB_STDOPT)) != 0 )
     {
         LogFile::ErrorMessage("ClamAV: Could not load database: %s\n", cl_strerror(ret));
         return false;
@@ -65,7 +65,7 @@
 
         cl_settempdir(Params::GetConfigString("TEMPDIR").c_str(), 0);
 
-        if ( (ret = cl_loaddbdir(dbdir, &root, &no)) != 0 )
+        if ( (ret = cl_load(dbdir, &root, &no, CL_DB_STDOPT)) != 0 )
         {
             LogFile::ErrorMessage("ClamAV: Could not reload database: %s\n", cl_strerror(ret));
             return false;
