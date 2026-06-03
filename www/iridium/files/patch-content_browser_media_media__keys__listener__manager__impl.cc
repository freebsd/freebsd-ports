--- content/browser/media/media_keys_listener_manager_impl.cc.orig	2025-12-10 15:04:57 UTC
+++ content/browser/media/media_keys_listener_manager_impl.cc
@@ -332,7 +332,7 @@ void MediaKeysListenerManagerImpl::StartListeningForMe
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Create SystemMediaControls with the SingletonHwnd.
   browser_system_media_controls_ =
       system_media_controls::SystemMediaControls::Create(
