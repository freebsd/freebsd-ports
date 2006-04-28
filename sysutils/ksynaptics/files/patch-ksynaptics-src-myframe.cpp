--- ksynaptics/src/myframe.cpp.orig	Thu Apr 27 02:00:53 2006
+++ ksynaptics/src/myframe.cpp	Thu Apr 27 02:01:45 2006
@@ -56,7 +56,7 @@
     kdDebug() << k_funcinfo << endl;
     
     // range checking
-    if ( ( i < NoTrigger ) or ( i >= PadModeMax ) )
+    if ( ( i < NoTrigger ) || ( i >= PadModeMax ) )
         mPadMode = NoTrigger;
     else
         mPadMode = (PadMode) i;
@@ -112,7 +112,7 @@
 
     // otherwise draw the corners/edges
     // TODO improve this drawing
-    if ( mPadMode != OneFinger and mPadMode != TwoFingers and mPadMode != ThreeFingers )
+    if ( mPadMode != OneFinger && mPadMode != TwoFingers && mPadMode != ThreeFingers )
     {
         myPainting.setPen( QColor( "Red" ) );
         myPainting.setBrush( QColor( "Red") );
