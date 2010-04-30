--- modules/xcos/src/java/org/scilab/modules/graph/ScilabCanvas.java.orig	2010-04-21 20:20:59.000000000 -0700
+++ modules/xcos/src/java/org/scilab/modules/graph/ScilabCanvas.java	2010-04-21 20:21:25.000000000 -0700
@@ -265,7 +265,7 @@
 				boolean dashed = mxUtils.isTrue(style,
 						mxConstants.STYLE_DASHED, false);
 				drawConnector(pts, penWidth, penColor, startMarker, startSize,
-						endMarker, endSize, dashed, rounded);
+						endMarker, endSize, rounded, style);
 				
 				Object centerMarker = style.get(ScilabConstants.STYLE_CENTERARROW);
 				if (centerMarker != null) {
