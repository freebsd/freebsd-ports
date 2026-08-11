--- modules/gui/qt/qt6.pro.orig	2026-07-20 18:14:35 UTC
+++ modules/gui/qt/qt6.pro
@@ -21,6 +21,10 @@ QTPLUGIN += qxcb-glx-integration qxcb-egl-integration 
 QTPLUGIN += qxcb-glx-integration qxcb-egl-integration qxcb qwayland-generic qwayland-egl qgtk3 qxdgdesktopportal xdg-shell
 }
 
+freebsd {
+QTPLUGIN += qxcb-glx-integration qxcb-egl-integration qxcb qwayland-generic qwayland-egl qgtk3 qxdgdesktopportal xdg-shell
+}
+
 macx {
 QTPLUGIN += qcocoa qmacstyle
 }
