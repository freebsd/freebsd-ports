--- core/HtmlFile/HtmlFile.pro.orig	2026-05-17 15:03:58 UTC
+++ core/HtmlFile/HtmlFile.pro
@@ -49,6 +49,10 @@
 
 ADD_DEPENDENCY(kernel, UnicodeConverter)
 
+core_freebsd {
+    DEFINES += asc_static_link_libstd
+}
+
 core_linux {
     DEFINES += asc_static_link_libstd
 }
