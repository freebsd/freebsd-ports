--- third_party/blink/renderer/core/html/forms/internal_popup_menu.cc.orig	2020-07-07 21:58:17 UTC
+++ third_party/blink/renderer/core/html/forms/internal_popup_menu.cc
@@ -113,7 +113,7 @@ class InternalPopupMenu::ItemIterationContext {
         is_in_group_(false),
         buffer_(buffer) {
     DCHECK(buffer_);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // On other platforms, the <option> background color is the same as the
     // <select> background color. On Linux, that makes the <option>
     // background color very dark, so by default, try to use a lighter
