--- third_party/WebKit/Source/core/html/forms/InternalPopupMenu.cpp.orig	2017-09-10 01:24:52.757075000 +0200
+++ third_party/WebKit/Source/core/html/forms/InternalPopupMenu.cpp	2017-09-10 01:25:11.778614000 +0200
@@ -157,7 +157,7 @@
         is_in_group_(false),
         buffer_(buffer) {
     DCHECK(buffer_);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // On other platforms, the <option> background color is the same as the
     // <select> background color. On Linux, that makes the <option>
     // background color very dark, so by default, try to use a lighter
