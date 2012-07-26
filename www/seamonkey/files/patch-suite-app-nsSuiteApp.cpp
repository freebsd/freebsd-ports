--- suite/app/nsSuiteApp.cpp~
+++ suite/app/nsSuiteApp.cpp
@@ -215,6 +215,8 @@ int main(int argc, char* argv[])
 #ifdef XP_MACOSX
   TriggerQuirks();
 #endif
+
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko19:%%LOCALBASE%%/lib/npapi/symlinks/seamonkey", 0);
   
   nsresult rv = mozilla::BinaryPath::Get(argv[0], exePath);
   if (NS_FAILED(rv)) {
