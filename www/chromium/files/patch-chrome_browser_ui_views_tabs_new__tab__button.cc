--- chrome/browser/ui/views/tabs/new_tab_button.cc.orig	2019-03-11 22:00:54 UTC
+++ chrome/browser/ui/views/tabs/new_tab_button.cc
@@ -63,7 +63,7 @@ const gfx::Size NewTabButton::kButtonSize{28, 28};
 NewTabButton::NewTabButton(TabStrip* tab_strip, views::ButtonListener* listener)
     : views::ImageButton(listener), tab_strip_(tab_strip) {
   set_animate_on_state_change(true);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   set_triggerable_event_flags(triggerable_event_flags() |
                               ui::EF_MIDDLE_MOUSE_BUTTON);
 #endif
