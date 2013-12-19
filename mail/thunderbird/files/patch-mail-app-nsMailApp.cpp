--- mail/app/nsMailApp.cpp~
+++ mail/app/nsMailApp.cpp
@@ -154,6 +154,7 @@ int main(int argc, char* argv[])
   TriggerQuirks();
 #endif
 
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
   nsresult rv = mozilla::BinaryPath::Get(argv[0], exePath);
   if (NS_FAILED(rv)) {
     Output("Couldn't calculate the application directory.\n");
