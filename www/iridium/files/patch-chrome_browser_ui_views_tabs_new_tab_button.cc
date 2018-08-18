--- chrome/browser/ui/views/tabs/new_tab_button.cc.orig	2017-09-10 00:35:35.638045000 +0200
+++ chrome/browser/ui/views/tabs/new_tab_button.cc	2017-09-10 00:36:04.851309000 +0200
@@ -49,7 +49,7 @@
       destroyed_(nullptr),
       new_tab_promo_observer_(this) {
   set_animate_on_state_change(true);
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   set_triggerable_event_flags(triggerable_event_flags() |
                               ui::EF_MIDDLE_MOUSE_BUTTON);
 #endif
