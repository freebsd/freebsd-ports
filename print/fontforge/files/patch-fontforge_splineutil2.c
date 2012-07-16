Index: fontforge/splineutil2.c
@@ -4813,7 +4813,8 @@ SplineSet *SplineSetReverse(SplineSet *s
     Spline *spline, *first, *next;
     BasePoint tp;
     SplinePoint *temp;
-    int bool;
+    int b;
+#define bool b
     int i;
     /* reverse the splineset so that what was the start point becomes the end */
     /*  and vice versa. This entails reversing every individual spline, and */
