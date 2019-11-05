--- third_party/blink/renderer/core/html/forms/internal_popup_menu.cc.orig	2019-10-21 19:06:43 UTC
+++ third_party/blink/renderer/core/html/forms/internal_popup_menu.cc
@@ -121,7 +121,7 @@ class InternalPopupMenu::ItemIterationContext {
         is_in_group_(false),
         buffer_(buffer) {
     DCHECK(buffer_);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // On other platforms, the <option> background color is the same as the
     // <select> background color. On Linux, that makes the <option>
     // background color very dark, so by default, try to use a lighter
