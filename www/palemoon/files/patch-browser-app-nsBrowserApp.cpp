--- browser/app/nsBrowserApp.cpp.orig	2017-11-14 14:36:13 UTC
+++ browser/app/nsBrowserApp.cpp
@@ -409,6 +409,9 @@ int main(int argc, char* argv[])
 #endif
   uint64_t start = TimeStamp_Now();
 
+  setenv("MOZ_GMP_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+
 #ifdef XP_MACOSX
   TriggerQuirks();
 #endif
