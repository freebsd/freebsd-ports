--- ksynaptics/src/synconfigwidget.cpp.orig	Thu Apr 27 01:52:23 2006
+++ ksynaptics/src/synconfigwidget.cpp	Thu Apr 27 01:52:55 2006
@@ -320,7 +320,7 @@
   // initialize the edge widget with the proper value
   scrollingStateFrame->displayState( SynConfig::circularScrollTrigger() );
   
-  if (!( Pad::hasDriver() and Pad::hasShm() ))
+  if (!( Pad::hasDriver() && Pad::hasShm() ))
       disableEverything();
 }
 
