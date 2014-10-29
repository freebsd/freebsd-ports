--- qtox.pro.orig	2014-10-28 21:27:51.000000000 +0100
+++ qtox.pro	2014-10-29 19:21:51.000000000 +0100
@@ -213,3 +213,15 @@
     src/video/netvideosource.cpp \
     src/widget/form/tabcompleter.cpp \
     src/video/videoframe.cpp
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
