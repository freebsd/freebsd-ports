--- src/mouse.h.orig	2012-10-08 01:40:07 UTC
+++ src/mouse.h
@@ -220,10 +220,13 @@ typedef struct _MouseDevRec {
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
@@ -262,6 +265,8 @@ typedef struct _MouseDevRec {
     int                 doubleClickOldSourceState;
     int                 lastMappedButtons;
     int                 buttonMap[MSE_MAXBUTTONS];
+    float               fracdx,fracdy;
+    float               sensitivity;
 } MouseDevRec, *MouseDevPtr;
 
 #endif /* _XF86OSMOUSE_H_ */
