--- remoting/host/create_desktop_interaction_strategy_factory.cc.orig	2026-01-16 13:40:34 UTC
+++ remoting/host/create_desktop_interaction_strategy_factory.cc
@@ -12,7 +12,7 @@
 #include "remoting/host/desktop_interaction_strategy.h"
 #include "remoting/host/legacy_interaction_strategy.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/gnome_interaction_strategy.h"
 #include "remoting/host/linux/gnome_remote_desktop_session.h"
 #include "remoting/host/linux/portal_interaction_strategy.h"
@@ -27,7 +27,7 @@ CreateDesktopInteractionStrategyFactory(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner,
     scoped_refptr<base::SingleThreadTaskRunner> video_capture_task_runner,
     scoped_refptr<base::SingleThreadTaskRunner> input_task_runner) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (webrtc::DesktopCapturer::IsRunningUnderWayland()) {
     if (GnomeRemoteDesktopSession::IsRunningUnderGnome()) {
       return std::make_unique<GnomeInteractionStrategyFactory>(ui_task_runner);
