--- comm/mail/app/nsMailApp.cpp.orig	2017-03-21 17:00:12 UTC
+++ comm/mail/app/nsMailApp.cpp
@@ -322,6 +322,9 @@ int main(int argc, char* argv[], char* e
 {
   mozilla::TimeStamp start = mozilla::TimeStamp::Now();
 
+  setenv("MOZ_GMP_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+
 #ifdef HAS_DLL_BLOCKLIST
   DllBlocklist_Initialize();
 
