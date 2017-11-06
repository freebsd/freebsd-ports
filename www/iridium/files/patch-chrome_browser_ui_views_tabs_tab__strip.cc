--- chrome/browser/ui/views/tabs/tab_strip.cc.orig	2017-04-19 19:06:30 UTC
+++ chrome/browser/ui/views/tabs/tab_strip.cc
@@ -323,7 +323,7 @@ NewTabButton::NewTabButton(TabStrip* tab
       tab_strip_(tab_strip),
       destroyed_(NULL) {
   set_animate_on_state_change(true);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   set_triggerable_event_flags(triggerable_event_flags() |
                               ui::EF_MIDDLE_MOUSE_BUTTON);
 #endif
