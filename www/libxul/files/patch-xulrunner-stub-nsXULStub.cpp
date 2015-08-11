--- xulrunner/stub/nsXULStub.cpp~
+++ xulrunner/stub/nsXULStub.cpp
@@ -160,6 +160,9 @@ main(int argc, char **argv)
   char greDir[MAXPATHLEN];
   bool greFound = false;
 
+  setenv("MOZ_GMP_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+
 #if defined(XP_MACOSX)
   CFBundleRef appBundle = CFBundleGetMainBundle();
   if (!appBundle)
