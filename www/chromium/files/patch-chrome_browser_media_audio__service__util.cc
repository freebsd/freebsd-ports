--- chrome/browser/media/audio_service_util.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/media/audio_service_util.cc
@@ -20,7 +20,7 @@
 
 namespace {
 
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
 bool GetPolicyOrFeature(const char* policy_name, const base::Feature& feature) {
   const policy::PolicyMap& policies =
@@ -40,7 +40,7 @@ bool GetPolicyOrFeature(const char* policy_name, const
 bool IsAudioServiceSandboxEnabled() {
 // TODO(crbug.com/1052397): Remove !IS_CHROMEOS_LACROS once lacros starts being
 // built with OS_CHROMEOS instead of OS_LINUX.
-#if defined(OS_WIN) || defined(OS_MAC) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
   return GetPolicyOrFeature(policy::key::kAudioSandboxEnabled,
                             features::kAudioServiceSandbox);
