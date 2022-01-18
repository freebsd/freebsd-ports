--- core/DesktopEditor/doctrenderer/app_builder/docbuilder.pro.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/doctrenderer/app_builder/docbuilder.pro
@@ -44,5 +44,8 @@ ADD_DEPENDENCY(graphics, kernel, UnicodeConverter, doc
 core_linux {
     LIBS += -ldl
 }
+core_freebsd {
+    LIBS += -liconv
+}
 
 SOURCES += main.cpp
