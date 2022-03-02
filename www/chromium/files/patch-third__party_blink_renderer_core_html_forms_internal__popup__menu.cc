--- third_party/blink/renderer/core/html/forms/internal_popup_menu.cc.orig	2022-02-28 16:54:41 UTC
+++ third_party/blink/renderer/core/html/forms/internal_popup_menu.cc
@@ -159,7 +159,7 @@ class InternalPopupMenu::ItemIterationContext {
         is_in_group_(false),
         buffer_(buffer) {
     DCHECK(buffer_);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     // On other platforms, the <option> background color is the same as the
     // <select> background color. On Linux, that makes the <option>
     // background color very dark, so by default, try to use a lighter
