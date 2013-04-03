--- browser/app/nsBrowserApp.cpp~
+++ browser/app/nsBrowserApp.cpp
@@ -334,6 +334,7 @@ int main(int argc, char* argv[])
   TriggerQuirks();
 #endif
 
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko19:%%LOCALBASE%%/lib/npapi/symlinks/firefox", 0);
   int gotCounters;
 #if defined(XP_UNIX)
   struct rusage initialRUsage;
