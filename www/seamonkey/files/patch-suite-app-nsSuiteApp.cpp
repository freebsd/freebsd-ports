--- suite/app/nsSuiteApp.cpp.orig	2017-07-07 05:15:27 UTC
+++ suite/app/nsSuiteApp.cpp
@@ -318,6 +318,9 @@ int main(int argc, char* argv[], char* envp[])
 {
   mozilla::TimeStamp start = mozilla::TimeStamp::Now();
 
+  setenv("MOZ_GMP_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+
 #ifdef HAS_DLL_BLOCKLIST
   DllBlocklist_Initialize();
 
