--- chrome/common/crash_keys.cc.orig	2026-10-18 13:29:39 UTC
+++ chrome/common/crash_keys.cc
@@ -126,6 +126,7 @@ void AllocateCrashKeyInBrowserAndChildren(std::string_
   GetCommandLineStringAnnotations().emplace_back(std::string(key)).Set(value);
 }
 
+#if BUILDFLAG(USE_CRASHPAD_ANNOTATION)
 void AppendStringAnnotationsCommandLineSwitch(base::CommandLine* command_line) {
   std::string string_annotations;
   for (const auto& crash_key : GetCommandLineStringAnnotations()) {
@@ -140,6 +141,7 @@ void AppendStringAnnotationsCommandLineSwitch(base::Co
   }
   command_line->AppendSwitchASCII(kStringAnnotationsSwitch, string_annotations);
 }
+#endif
 
 void SetCrashKeysFromCommandLine(const base::CommandLine& command_line) {
   SetStringAnnotations(command_line);
