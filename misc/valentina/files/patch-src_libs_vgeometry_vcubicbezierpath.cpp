--- src/libs/vgeometry/vcubicbezierpath.cpp.orig	2026-06-12 19:33:33 UTC
+++ src/libs/vgeometry/vcubicbezierpath.cpp
@@ -312,7 +312,7 @@ auto VCubicBezierPath::CountSubSpl(vsizetype size) -> 
         return 0;
     }
 #if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
-    return qFloor(qAbs((size - 4) / 3.0L + 1));
+    return qFloor(qAbs((static_cast<long double>(size) - 4) / 3.0L + 1));
 #else
     return qFloor(qAbs((size - 4) / 3.0 + 1));
 #endif
