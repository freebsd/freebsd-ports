--- browser/app/nsBrowserApp.cpp.orig	2016-09-19 16:19:28 UTC
+++ browser/app/nsBrowserApp.cpp
@@ -324,6 +324,9 @@ int main(int argc, char* argv[], char* e
 {
   mozilla::TimeStamp start = mozilla::TimeStamp::Now();
 
+  setenv("MOZ_GMP_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+
 #ifdef HAS_DLL_BLOCKLIST
   DllBlocklist_Initialize();
 
