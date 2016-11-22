--- third_party/WebKit/Source/web/PopupMenuImpl.cpp.orig	2016-07-20 22:03:42.000000000 +0300
+++ third_party/WebKit/Source/web/PopupMenuImpl.cpp	2016-08-12 10:26:08.695632000 +0300
@@ -155,7 +155,7 @@
         , m_buffer(buffer)
     {
         DCHECK(m_buffer);
-#if OS(LINUX)
+#if OS(LINUX) || OS(BSD)
         // On other platforms, the <option> background color is the same as the
         // <select> background color. On Linux, that makes the <option>
         // background color very dark, so by default, try to use a lighter
