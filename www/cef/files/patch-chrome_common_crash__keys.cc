--- chrome/common/crash_keys.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/common/crash_keys.cc
@@ -56,7 +56,9 @@ class CrashKeyWithName {
   ~CrashKeyWithName() = delete;
 
   std::string_view Name() const { return name_; }
+#if BUILDFLAG(USE_CRASHPAD_ANNOTATION)
   std::string_view Value() const { return crash_key_.value(); }
+#endif
   void Clear() { crash_key_.Clear(); }
   void Set(std::string_view value) { crash_key_.Set(value); }
 
@@ -200,6 +202,7 @@ void AllocateCrashKeyInBrowserAndChildren(std::string_
   GetCommandLineStringAnnotations().emplace_back(std::string(key)).Set(value);
 }
 
+#if BUILDFLAG(USE_CRASHPAD_ANNOTATION)
 void AppendStringAnnotationsCommandLineSwitch(base::CommandLine* command_line) {
   std::string string_annotations;
   for (const auto& crash_key : GetCommandLineStringAnnotations()) {
@@ -214,6 +217,7 @@ void AppendStringAnnotationsCommandLineSwitch(base::Co
   }
   command_line->AppendSwitchASCII(kStringAnnotationsSwitch, string_annotations);
 }
+#endif
 
 void SetCrashKeysFromCommandLine(const base::CommandLine& command_line) {
   SetStringAnnotations(command_line);
