diff --git browser/app/nsBrowserApp.cpp browser/app/nsBrowserApp.cpp
index e1f11b9cfd..a15b129402 100644
--- browser/app/nsBrowserApp.cpp
+++ browser/app/nsBrowserApp.cpp
@@ -341,6 +341,9 @@ int main(int argc, char* argv[], char* envp[]) {
     }
 #  endif
 
+    setenv("MOZ_GMP_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+    setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+
 #  ifdef HAS_DLL_BLOCKLIST
     uint32_t initFlags =
         gBlocklistInitFlags | eDllBlocklistInitFlagIsChildProcess;
