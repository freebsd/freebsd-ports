--- kiltdown/hoverbutton.cc.orig	Mon May 14 05:25:23 2001
+++ kiltdown/hoverbutton.cc	Wed Dec 25 12:29:01 2002
@@ -28,7 +28,7 @@
 (
     const QString & text,
     QWidget * parent,
-    const char * name=0
+    const char * name
 ) : QPushButton(text, parent, name)
 {
     this->setFlat(true);
@@ -47,7 +47,7 @@
     const QIconSet & icon,
     const QString & text,
     QWidget * parent,
-    const char * name=0
+    const char * name
 ) : QPushButton(icon, text, parent, name)
 {
     this->setFlat(true);
