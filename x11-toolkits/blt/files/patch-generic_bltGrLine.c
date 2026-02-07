--- generic/bltGrLine.c.orig	2013-11-18 17:51:32.000000000 +0100
+++ generic/bltGrLine.c	2013-11-18 17:51:47.000000000 +0100
@@ -1211,7 +1211,7 @@
 NameOfSmooth(value)
     Smoothing value;
 {
-    if ((value < 0) || (value >= PEN_SMOOTH_LAST)) {
+    if ((value == 0) || (value >= PEN_SMOOTH_LAST)) {
 	return "unknown smooth value";
     }
     return smoothingInfo[value].name;
