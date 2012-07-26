--- browser/app/nsBrowserApp.cpp~
+++ browser/app/nsBrowserApp.cpp
@@ -197,6 +197,7 @@ int main(int argc, char* argv[])
   TriggerQuirks();
 #endif
 
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko19:%%LOCALBASE%%/lib/npapi/symlinks/firefox", 0);
   nsresult rv = mozilla::BinaryPath::Get(argv[0], exePath);
   if (NS_FAILED(rv)) {
     Output("Couldn't calculate the application directory.\n");
