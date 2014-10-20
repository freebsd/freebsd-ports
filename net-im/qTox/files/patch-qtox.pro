--- qtox.pro.orig	2014-10-18 16:44:41 UTC
+++ qtox.pro
@@ -186,3 +186,15 @@
     src/cameraworker.cpp \
     src/widget/videosurface.cpp \
     src/netvideosource.cpp
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
