--- style/baghira.cpp.orig	Thu Nov 11 05:55:20 2004
+++ style/baghira.cpp	Fri Nov 19 21:21:49 2004
@@ -1597,7 +1597,7 @@
                 const QPushButton *btn = ( const QPushButton* ) widget;
                 int x, y, w, h;
                 r.rect( &x, &y, &w, &h );
-                bool highlighted = btn->isOn() || btn->isDown() || btn->hasFocus() || btn == highlightWidget;
+                bool highlighted = btn->isOn() || btn->isDown() || btn->hasFocus() || btn == ( const QPushButton* ) highlightWidget;
     
                 if ( btn->isOn() || btn->isDown() )
                     {
