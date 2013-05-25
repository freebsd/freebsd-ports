--- src/mouse.h.orig	2012-07-27 08:10:56.000000000 +0200
+++ src/mouse.h	2012-07-30 00:41:02.000000000 +0200
@@ -217,10 +217,13 @@
     Bool                emulate3ButtonsSoft;
     int                 emulate3Timeout;/* Timeout for 3 button emulation */
     Bool                chordMiddle;
+    Bool                disableXY;
     Bool                flipXY;
     int                 invX;
     int                 invY;
     int                 resolution;
+    Bool                hasW;
+    Bool                hasZ;
     int                 negativeZ;      /* button mask */
     int                 positiveZ;      /* button mask */
     int                 negativeW;      /* button mask */
@@ -259,6 +262,8 @@
     int                 doubleClickOldSourceState;
     int                 lastMappedButtons;
     int                 buttonMap[MSE_MAXBUTTONS];
+    float               fracdx,fracdy;
+    float               sensitivity;
 } MouseDevRec, *MouseDevPtr;
 
 #endif /* _XF86OSMOUSE_H_ */
