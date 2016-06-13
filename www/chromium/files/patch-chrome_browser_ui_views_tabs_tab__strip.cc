--- chrome/browser/ui/views/tabs/tab_strip.cc.orig	2016-06-06 21:05:14.000000000 +0200
+++ chrome/browser/ui/views/tabs/tab_strip.cc	2016-06-13 22:03:03.000000000 +0200
@@ -331,7 +331,7 @@
     : views::ImageButton(listener),
       tab_strip_(tab_strip),
       destroyed_(NULL) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   set_triggerable_event_flags(triggerable_event_flags() |
                               ui::EF_MIDDLE_MOUSE_BUTTON);
 #endif
