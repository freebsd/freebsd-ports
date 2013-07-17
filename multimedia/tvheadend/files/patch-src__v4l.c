--- src/v4l.c.orig	2012-11-07 11:46:15.000000000 +0100
+++ src/v4l.c	2012-12-19 21:55:37.554141683 +0100
@@ -458,7 +458,7 @@
 	   "%s: Standard #%d: %016llx %s, frameperiod: %d/%d, %d lines",
 	   path,
 	   standard.index, 
-	   standard.id,
+	   (long long unsigned int)standard.id,
 	   standard.name,
 	   standard.frameperiod.numerator,
 	   standard.frameperiod.denominator,
@@ -499,7 +499,7 @@
 	   type,
 	   input.audioset,
 	   input.tuner,
-	   input.std,
+	   (long long unsigned int)input.std,
 	   f & V4L2_IN_ST_NO_POWER  ? "[No power] " : "",
 	   f & V4L2_IN_ST_NO_SIGNAL ? "[No signal] " : "",
 	   f & V4L2_IN_ST_NO_COLOR  ? "[No color] " : "");
