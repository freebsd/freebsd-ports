--- mail/app/nsMailApp.cpp~
+++ mail/app/nsMailApp.cpp
@@ -320,6 +320,9 @@ int main(int argc, char* argv[])
   TriggerQuirks();
 #endif
 
+  setenv("MOZ_GMP_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+
   int gotCounters;
 #if defined(XP_UNIX)
   struct rusage initialRUsage;
