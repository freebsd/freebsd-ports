--- third_party/blink/renderer/core/html/forms/internal_popup_menu.cc.orig	2018-07-19 19:21:46.343805000 +0200
+++ third_party/blink/renderer/core/html/forms/internal_popup_menu.cc	2018-07-19 19:22:00.957461000 +0200
@@ -126,7 +126,7 @@
         is_in_group_(false),
         buffer_(buffer) {
     DCHECK(buffer_);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // On other platforms, the <option> background color is the same as the
     // <select> background color. On Linux, that makes the <option>
     // background color very dark, so by default, try to use a lighter
