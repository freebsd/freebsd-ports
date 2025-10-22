--- chrome/browser/ui/tabs/tab_features.cc.orig	2025-10-21 16:57:35 UTC
+++ chrome/browser/ui/tabs/tab_features.cc
@@ -366,7 +366,7 @@ void TabFeatures::Init(TabInterface& tab, Profile* pro
   task_manager::WebContentsTags::CreateForTabContents(tab.GetContents());
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   inactive_window_mouse_event_controller_ =
       std::make_unique<InactiveWindowMouseEventController>();
 
