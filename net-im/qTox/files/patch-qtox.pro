--- qtox.pro
+++ qtox.pro
@@ -451,3 +451,15 @@
     src/widget/gui.h \
     src/toxme.h \
     src/misc/qrwidget.h
+
+unix {
+    target.path  = $$PREFIX/bin
+
+    desktop.files = qTox.desktop
+    desktop.path = $$PREFIX/share/applications
+
+    icon.files = img/qtox.png
+    icon.path = $$PREFIX/share/pixmaps
+
+    INSTALLS = target desktop icon
+}
