--- chrome/browser/ui/views/tabs/new_tab_button.cc.orig	2020-11-13 06:36:38 UTC
+++ chrome/browser/ui/views/tabs/new_tab_button.cc
@@ -57,7 +57,7 @@ class NewTabButton::HighlightPathGenerator
 NewTabButton::NewTabButton(TabStrip* tab_strip, PressedCallback callback)
     : views::ImageButton(std::move(callback)), tab_strip_(tab_strip) {
   SetAnimateOnStateChange(true);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   SetTriggerableEventFlags(GetTriggerableEventFlags() |
                            ui::EF_MIDDLE_MOUSE_BUTTON);
 #endif
