diff --git comm/mail/app/nsMailApp.cpp comm/mail/app/nsMailApp.cpp
index 3db646e89d..2318337f7b 100644
--- comm/mail/app/nsMailApp.cpp
+++ comm/mail/app/nsMailApp.cpp
@@ -280,6 +280,9 @@ int main(int argc, char* argv[], char* envp[]) {
 
   mozilla::TimeStamp start = mozilla::TimeStamp::Now();
 
+  setenv("MOZ_GMP_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+  setenv("MOZ_PLUGIN_PATH", "%%LOCALBASE%%/lib/browser_plugins/symlinks/gecko", 0);
+
   // Make sure we unregister the runtime exception module before returning.
   // We do this here to cover both registers for child and main processes.
   auto unregisterRuntimeExceptionModule =
