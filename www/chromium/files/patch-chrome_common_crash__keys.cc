--- chrome/common/crash_keys.cc.orig	2025-03-05 08:14:56 UTC
+++ chrome/common/crash_keys.cc
@@ -52,7 +52,9 @@ class CrashKeyWithName {
   ~CrashKeyWithName() = delete;
 
   std::string_view Name() const { return name_; }
+#if BUILDFLAG(USE_CRASHPAD_ANNOTATION)
   std::string_view Value() const { return crash_key_.value(); }
+#endif
   void Clear() { crash_key_.Clear(); }
   void Set(std::string_view value) { crash_key_.Set(value); }
 
@@ -197,6 +199,7 @@ void AllocateCrashKeyInBrowserAndChildren(std::string_
   GetCommandLineStringAnnotations().emplace_back(std::string(key)).Set(value);
 }
 
+#if BUILDFLAG(USE_CRASHPAD_ANNOTATION)
 void AppendStringAnnotationsCommandLineSwitch(base::CommandLine* command_line) {
   std::string string_annotations;
   for (const auto& crash_key : GetCommandLineStringAnnotations()) {
@@ -211,6 +214,7 @@ void AppendStringAnnotationsCommandLineSwitch(base::Co
   }
   command_line->AppendSwitchASCII(kStringAnnotationsSwitch, string_annotations);
 }
+#endif
 
 void SetCrashKeysFromCommandLine(const base::CommandLine& command_line) {
   SetStringAnnotations(command_line);
