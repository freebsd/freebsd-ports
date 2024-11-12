--- browser/app/nsBrowserApp.cpp.orig	2024-10-21 21:51:41.000000000 +0200
+++ browser/app/nsBrowserApp.cpp	2024-11-07 21:47:05.301097000 +0100
@@ -391,6 +391,11 @@
   // Register an external module to report on otherwise uncatchable exceptions.
   CrashReporter::RegisterRuntimeExceptionModule();
 
+  setenv("MOZ_GMP_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("FONTCONFIG_PATH", "%%LOCALBASE%%/lib/tor-browser/fontconfig/", 1);
+  setenv("FONTCONFIG_FILE", "fonts.conf", 1);
+
 #ifdef HAS_DLL_BLOCKLIST
   DllBlocklist_Initialize(gBlocklistInitFlags);
 #endif
