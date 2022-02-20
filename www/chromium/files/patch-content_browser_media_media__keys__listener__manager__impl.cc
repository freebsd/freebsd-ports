--- content/browser/media/media_keys_listener_manager_impl.cc.orig	2022-02-07 13:39:41 UTC
+++ content/browser/media/media_keys_listener_manager_impl.cc
@@ -226,7 +226,7 @@ void MediaKeysListenerManagerImpl::StartListeningForMe
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_WIN) || \
-    defined(OS_MAC)
+    defined(OS_MAC) || defined(OS_BSD)
   system_media_controls_ = system_media_controls::SystemMediaControls::Create(
       media::AudioManager::GetGlobalAppName());
 #endif
