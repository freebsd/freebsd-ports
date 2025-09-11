--- remoting/host/create_desktop_interaction_strategy_factory.cc.orig	2025-09-10 13:22:16 UTC
+++ remoting/host/create_desktop_interaction_strategy_factory.cc
@@ -13,7 +13,7 @@
 #include "remoting/host/desktop_interaction_strategy.h"
 #include "remoting/host/legacy_interaction_strategy.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/linux/gnome_interaction_strategy.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -25,7 +25,7 @@ CreateDesktopInteractionStrategyFactory(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner,
     scoped_refptr<base::SingleThreadTaskRunner> video_capture_task_runner,
     scoped_refptr<base::SingleThreadTaskRunner> input_task_runner) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::CommandLine::ForCurrentProcess()->HasSwitch("enable-wayland")) {
     return std::make_unique<GnomeInteractionStrategyFactory>(ui_task_runner);
   }
