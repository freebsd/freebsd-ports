--- chrome/browser/media/audio_service_util.cc.orig	2021-03-12 23:57:18 UTC
+++ chrome/browser/media/audio_service_util.cc
@@ -24,7 +24,7 @@ bool IsAudioServiceSandboxEnabled() {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
   const policy::PolicyMap& policies =
       g_browser_process->browser_policy_connector()
           ->GetPolicyService()
