--- core/DesktopEditor/doctrenderer/doctrenderer.pro.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/doctrenderer/doctrenderer.pro
@@ -65,6 +65,10 @@ SOURCES += \
     embed/NativeControlEmbed.cpp \
     embed/NativeBuilderEmbed.cpp
 
+core_freebsd {
+    LIBS += -lexecinfo
+}
+
 core_mac {
     !use_v8:CONFIG += use_javascript_core
 }
