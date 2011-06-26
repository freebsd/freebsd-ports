--- demo/oxygengtkdeco_main.cpp~	2011-06-26 11:15:05.000000000 -0300
+++ demo/oxygengtkdeco_main.cpp	2011-06-26 11:16:02.000000000 -0300
@@ -118,7 +118,7 @@ int dh=0;
 gboolean initLib()
 {
     void* library;
-    char* error=0;
+    const char* error=0;
     char* moduleDir=gtk_rc_get_module_dir();
     if(moduleDir)
     {
