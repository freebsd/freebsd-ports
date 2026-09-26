--- chrome/browser/ui/views/tabs/shared/new_tab_button.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/views/tabs/shared/new_tab_button.cc
@@ -45,7 +45,7 @@ NewTabButton::NewTabButton(BrowserWindowInterface* bro
 
   set_context_menu_controller(this);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, middle-clicking the New Tab Button triggers
   // paste and navigate, either to URLs or to search queries.
   SetTriggerableEventFlags(GetTriggerableEventFlags() |
@@ -116,7 +116,7 @@ void NewTabButton::SetMiddleClickCallbackForTesting(
 }
 
 void NewTabButton::NotifyClick(const ui::Event& event) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event.IsMouseEvent()) {
     const ui::MouseEvent& mouse = static_cast<const ui::MouseEvent&>(event);
     if (mouse.IsOnlyMiddleMouseButton()) {
