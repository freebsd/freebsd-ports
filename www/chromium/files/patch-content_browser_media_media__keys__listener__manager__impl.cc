--- content/browser/media/media_keys_listener_manager_impl.cc.orig	2026-10-18 13:29:39 UTC
+++ content/browser/media/media_keys_listener_manager_impl.cc
@@ -331,7 +331,7 @@ void MediaKeysListenerManagerImpl::StartListeningForMe
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // Create SystemMediaControls with the SingletonHwnd.
   browser_system_media_controls_ =
       system_media_controls::SystemMediaControls::Create(
