--- Source/WebCore/rendering/shapes/BoxShape.cpp.orig	2015-07-22 12:37:57 UTC
+++ Source/WebCore/rendering/shapes/BoxShape.cpp
@@ -43,7 +43,7 @@ static inline LayoutUnit adjustRadiusFor
 
     LayoutUnit ratio = radius / margin;
     if (ratio < 1)
-        return radius + (margin * (1 + pow(ratio - 1, 3)));
+        return radius + (margin * (1 + pow(static_cast<float>(ratio) - 1, 3)));
 
     return radius + margin;
 }
