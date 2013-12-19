--- xulrunner/stub/nsXULStub.cpp~
+++ xulrunner/stub/nsXULStub.cpp
@@ -202,6 +202,8 @@ main(int argc, char **argv)
   char greDir[MAXPATHLEN];
   bool greFound = false;
 
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+
 #if defined(XP_MACOSX)
   CFBundleRef appBundle = CFBundleGetMainBundle();
   if (!appBundle)
