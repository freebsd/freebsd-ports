abs is not needed, as AnimInfo::animFrame is unsigned
--- style/polyester.cpp.orig	2009-02-17 18:23:09 UTC
+++ style/polyester.cpp
@@ -216,7 +216,7 @@ void PolyesterStyle::animate()
 
           if( animWidgets[widget].active == true ) {
             mustStop = false;
-              if(abs(animWidgets[widget].animFrame) < ANIMATIONSTEPS) {
+              if(animWidgets[widget].animFrame < ANIMATIONSTEPS) {
                   if ( _animateButton ) {
                       animWidgets[widget].animFrame += animationDelta;
                       widget->repaint();
@@ -225,7 +225,7 @@ void PolyesterStyle::animate()
                   }
               }
           } else {
-              if(abs(animWidgets[widget].animFrame) > 0) {
+              if(animWidgets[widget].animFrame != 0) {
                 mustStop = false;
                   if ( _animateButton ) {
                       animWidgets[widget].animFrame -= animationDelta;
