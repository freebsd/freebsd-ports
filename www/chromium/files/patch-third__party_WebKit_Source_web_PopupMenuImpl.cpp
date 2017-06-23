--- third_party/WebKit/Source/web/PopupMenuImpl.cpp.orig	2017-06-05 19:03:26 UTC
+++ third_party/WebKit/Source/web/PopupMenuImpl.cpp
@@ -155,7 +155,7 @@ class PopupMenuImpl::ItemIterationContext {
         is_in_group_(false),
         buffer_(buffer) {
     DCHECK(buffer_);
-#if OS(LINUX)
+#if OS(LINUX) || OS(BSD)
     // On other platforms, the <option> background color is the same as the
     // <select> background color. On Linux, that makes the <option>
     // background color very dark, so by default, try to use a lighter
