--- style/baghira.cpp.orig	Tue Aug 31 00:07:49 2004
+++ style/baghira.cpp	Thu Sep  2 12:57:28 2004
@@ -1643,7 +1643,7 @@
 				const QPushButton *btn = ( const QPushButton* ) widget;
 				int x, y, w, h;
 				r.rect( &x, &y, &w, &h );
-				bool highlighted = btn->isOn() || btn->isDown() || btn->hasFocus() || btn == highlightWidget;
+				bool highlighted = btn->isOn() || btn->isDown() || btn->hasFocus() || btn == ( const QPushButton* ) highlightWidget;
 
 				if ( btn->isOn() || btn->isDown() ) {
 					flags |= Style_Sunken;
