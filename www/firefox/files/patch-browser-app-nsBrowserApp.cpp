diff --git browser/app/nsBrowserApp.cpp browser/app/nsBrowserApp.cpp
index 87c2e16..a41f1d9 100644
--- browser/app/nsBrowserApp.cpp
+++ browser/app/nsBrowserApp.cpp
@@ -337,6 +337,9 @@ int main(int argc, char* argv[], char* envp[]) {
   }
 #endif
 
+  setenv("MOZ_GMP_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+
 #ifdef HAS_DLL_BLOCKLIST
   DllBlocklist_Initialize(gBlocklistInitFlags);
 #endif
