Convert old GNU field designator syntax to C99 syntax to remove some
annoying warnings. Fixed upstream in a870946.

--- track.c.orig	2016-10-25 01:39:24 UTC
+++ track.c
@@ -17,25 +17,25 @@
 
 
 struct trackoptions track_template = {
-    dev:            -1,             /* dev open */
-    port:           NULL,           /* char *port */
-    motorx:         0,              /* int motorx */
-    motory:         0,              /* int motory */
-    maxx:           0,              /* int maxx; */
-    maxy:           0,              /* int maxy; */
-    minx:           0,              /* int minx; */
-    miny:           0,              /* int miny; */
-    homex:          128,            /* int homex; */
-    homey:          128,            /* int homey; */
-    motorx_reverse: 0,              /* int reversed x servo; */
-    motory_reverse: 0,              /* int reversed y servo; */
-    speed:          TRACK_SPEED,    /* speed */
-    stepsize:       TRACK_STEPSIZE, /* stepsize */
-    active:         0,              /* auto tracking active */
-    minmaxfound:    0,              /* flag for minmax values stored for pwc based camera */
-    step_angle_x:   10,             /* UVC step angle in degrees X-axis that camera moves during auto tracking */
-    step_angle_y:   10,             /* UVC step angle in degrees Y-axis that camera moves during auto tracking */
-    move_wait:      10              /* number of frames to disable motion detection after camera moving */
+    .dev =            -1,             /* dev open */
+    .port =           NULL,           /* char *port */
+    .motorx =         0,              /* int motorx */
+    .motory =         0,              /* int motory */
+    .maxx =           0,              /* int maxx; */
+    .maxy =           0,              /* int maxy; */
+    .minx =           0,              /* int minx; */
+    .miny =           0,              /* int miny; */
+    .homex =          128,            /* int homex; */
+    .homey =          128,            /* int homey; */
+    .motorx_reverse = 0,              /* int reversed x servo; */
+    .motory_reverse = 0,              /* int reversed y servo; */
+    .speed =          TRACK_SPEED,    /* speed */
+    .stepsize =       TRACK_STEPSIZE, /* stepsize */
+    .active =         0,              /* auto tracking active */
+    .minmaxfound =    0,              /* flag for minmax values stored for pwc based camera */
+    .step_angle_x =   10,             /* UVC step angle in degrees X-axis that camera moves during auto tracking */
+    .step_angle_y =   10,             /* UVC step angle in degrees Y-axis that camera moves during auto tracking */
+    .move_wait =      10              /* number of frames to disable motion detection after camera moving */
 };
 
 
