--- core/HtmlFile/HtmlFile.pro.orig	2021-09-30 12:13:32 UTC
+++ core/HtmlFile/HtmlFile.pro
@@ -18,6 +18,10 @@ include(../Common/base.pri)
 
 ADD_DEPENDENCY(kernel, UnicodeConverter)
 
+core_freebsd {
+    DEFINES += asc_static_link_libstd
+}
+
 core_linux {
     DEFINES += asc_static_link_libstd
 }
