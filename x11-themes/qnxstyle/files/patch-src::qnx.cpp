--- src/qnx.cpp.orig	Wed Apr 17 16:03:57 2002
+++ src/qnx.cpp	Mon May 19 11:27:21 2003
@@ -1948,7 +1948,7 @@
 
 void QnxStyle::drawVGradient(QPainter *p, const QColorGroup &g,
                             QColorGroup::ColorRole type, int x, int y,
-                            int w, int h, int /*sx*/, int sy, int /*tw*/, int th, bool flip=false) const
+                            int w, int h, int /*sx*/, int sy, int /*tw*/, int th, bool flip) const
 {
     GradientSet *grSet = gDict.find(g.color(type).rgb());
     if(!grSet){
@@ -1980,7 +1980,7 @@
 
 void QnxStyle::drawHGradient(QPainter *p, const QColorGroup &g,
                             QColorGroup::ColorRole type, int x, int y,
-                            int w, int h, int sx, int /*sy*/, int tw, int /*th*/, bool flip=false ) const
+                            int w, int h, int sx, int /*sy*/, int tw, int /*th*/, bool flip) const
 {
     GradientSet *grSet = gDict.find(g.color(type).rgb());
     if(!grSet)
