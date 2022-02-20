--- content/utility/utility_main.cc.orig	2022-02-07 13:39:41 UTC
+++ content/utility/utility_main.cc
@@ -31,16 +31,22 @@
 #include "third_party/icu/source/common/unicode/unistr.h"
 #include "third_party/icu/source/i18n/unicode/timezone.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "content/utility/speech/speech_recognition_sandbox_hook_linux.h"
 #if BUILDFLAG(ENABLE_PRINTING)
 #include "printing/sandbox/print_backend_sandbox_hook_linux.h"
 #endif
+#if !defined(OS_BSD)
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 #include "services/audio/audio_sandbox_hook_linux.h"
 #include "services/network/network_sandbox_hook_linux.h"
 #endif
 
+#if defined(OS_BSD)
+#include "sandbox/policy/openbsd/sandbox_openbsd.h"
+#endif
+
 #if BUILDFLAG(IS_CHROMEOS_ASH)
 #include "ash/services/ime/ime_sandbox_hook.h"
 #include "chromeos/assistant/buildflags.h"
@@ -121,7 +127,7 @@ int UtilityMain(MainFunctionParams parameters) {
     }
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Initializes the sandbox before any threads are created.
   // TODO(jorgelo): move this after GTK initialization when we enable a strict
   // Seccomp-BPF policy.
@@ -165,6 +171,7 @@ int UtilityMain(MainFunctionParams parameters) {
     default:
       break;
   }
+#if !defined(OS_BSD)
   if (parameters.zygote_child || !pre_sandbox_hook.is_null()) {
     sandbox::policy::SandboxLinux::Options sandbox_options;
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -180,6 +187,11 @@ int UtilityMain(MainFunctionParams parameters) {
     sandbox::policy::Sandbox::Initialize(
         sandbox_type, std::move(pre_sandbox_hook), sandbox_options);
   }
+#else
+  sandbox::policy::Sandbox::Initialize(
+      sandbox_type, std::move(pre_sandbox_hook),
+      sandbox::policy::SandboxLinux::Options());
+#endif
 #elif defined(OS_WIN)
   g_utility_target_services = parameters.sandbox_info->target_services;
 #endif
