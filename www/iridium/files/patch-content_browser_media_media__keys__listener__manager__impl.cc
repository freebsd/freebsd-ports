--- content/browser/media/media_keys_listener_manager_impl.cc.orig	2024-08-01 05:47:53 UTC
+++ content/browser/media/media_keys_listener_manager_impl.cc
@@ -333,7 +333,7 @@ void MediaKeysListenerManagerImpl::StartListeningForMe
     return;
   }
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_WIN)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)) || BUILDFLAG(IS_WIN)
   // Create SystemMediaControls with the SingletonHwnd.
   browser_system_media_controls_ =
       system_media_controls::SystemMediaControls::Create(
