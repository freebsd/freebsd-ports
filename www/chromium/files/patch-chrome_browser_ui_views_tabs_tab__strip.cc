--- chrome/browser/ui/views/tabs/tab_strip.cc.orig	2016-05-11 19:02:16 UTC
+++ chrome/browser/ui/views/tabs/tab_strip.cc
@@ -333,7 +333,7 @@ NewTabButton::NewTabButton(TabStrip* tab
     : views::ImageButton(listener),
       tab_strip_(tab_strip),
       destroyed_(NULL) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   set_triggerable_event_flags(triggerable_event_flags() |
                               ui::EF_MIDDLE_MOUSE_BUTTON);
 #endif
