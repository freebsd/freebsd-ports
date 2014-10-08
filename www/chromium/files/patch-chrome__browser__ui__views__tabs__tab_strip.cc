--- chrome/browser/ui/views/tabs/tab_strip.cc.orig	2014-10-06 09:33:35.000000000 +0200
+++ chrome/browser/ui/views/tabs/tab_strip.cc	2014-10-06 09:31:58.000000000 +0200
@@ -281,7 +281,7 @@
     : views::ImageButton(listener),
       tab_strip_(tab_strip),
       destroyed_(NULL) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   set_triggerable_event_flags(triggerable_event_flags() |
                               ui::EF_MIDDLE_MOUSE_BUTTON);
 #endif
