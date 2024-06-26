--- content/browser/media/media_keys_listener_manager_impl.cc.orig	2024-06-25 12:08:48 UTC
+++ content/browser/media/media_keys_listener_manager_impl.cc
@@ -334,7 +334,7 @@ void MediaKeysListenerManagerImpl::StartListeningForMe
   }
 
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // Create SystemMediaControls with the SingletonHwnd.
   browser_system_media_controls_ =
       system_media_controls::SystemMediaControls::Create(
