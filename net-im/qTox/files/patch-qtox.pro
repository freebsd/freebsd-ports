--- qtox.pro
+++ qtox.pro
@@ -223,3 +223,15 @@
     src/misc/serialize.cpp \
     src/widget/form/settings/advancedform.cpp \
     src/audio.cpp
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
