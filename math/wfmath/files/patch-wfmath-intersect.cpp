--- wfmath/intersect.cpp.orig	2014-03-10 19:17:04.000000000 +0100
+++ wfmath/intersect.cpp	2014-03-10 19:18:00.000000000 +0100
@@ -31,121 +31,6 @@
 
 namespace WFMath {
 
-// force a bunch of instantiations
-
-template bool Intersect<2>(const Point<2>&, const Point<2>&, bool);
-template bool Intersect<3>(const Point<3>&, const Point<3>&, bool);
-template bool Contains<2>(const Point<2>&, const Point<2>&, bool);
-template bool Contains<3>(const Point<3>&, const Point<3>&, bool);
-
-template bool Intersect<Point<2>,AxisBox<2> >(const Point<2>&, const AxisBox<2>&, bool);
-template bool Intersect<Point<3>,AxisBox<3> >(const Point<3>&, const AxisBox<3>&, bool);
-template bool Contains<2>(const Point<2>&, const AxisBox<2>&, bool);
-template bool Contains<3>(const Point<3>&, const AxisBox<3>&, bool);
-template bool Intersect<2>(const AxisBox<2>&, const Point<2>&, bool);
-template bool Intersect<3>(const AxisBox<3>&, const Point<3>&, bool);
-template bool Contains<2>(const AxisBox<2>&, const Point<2>&, bool);
-template bool Contains<3>(const AxisBox<3>&, const Point<3>&, bool);
-
-template bool Intersect<2>(const AxisBox<2>&, const AxisBox<2>&, bool);
-template bool Intersect<3>(const AxisBox<3>&, const AxisBox<3>&, bool);
-template bool Contains<2>(const AxisBox<2>&, const AxisBox<2>&, bool);
-template bool Contains<3>(const AxisBox<3>&, const AxisBox<3>&, bool);
-
-template bool Intersect<Point<2>,Ball<2> >(const Point<2>&, const Ball<2>&, bool);
-template bool Intersect<Point<3>,Ball<3> >(const Point<3>&, const Ball<3>&, bool);
-template bool Contains<2>(const Point<2>&, const Ball<2>&, bool);
-template bool Contains<3>(const Point<3>&, const Ball<3>&, bool);
-template bool Intersect<2>(const Ball<2>&, const Point<2>&, bool);
-template bool Intersect<3>(const Ball<3>&, const Point<3>&, bool);
-template bool Contains<2>(const Ball<2>&, const Point<2>&, bool);
-template bool Contains<3>(const Ball<3>&, const Point<3>&, bool);
-
-template bool Intersect<AxisBox<2>,Ball<2> >(const AxisBox<2>&, const Ball<2>&, bool);
-template bool Intersect<AxisBox<3>,Ball<3> >(const AxisBox<3>&, const Ball<3>&, bool);
-template bool Contains<2>(const AxisBox<2>&, const Ball<2>&, bool);
-template bool Contains<3>(const AxisBox<3>&, const Ball<3>&, bool);
-template bool Intersect<2>(const Ball<2>&, const AxisBox<2>&, bool);
-template bool Intersect<3>(const Ball<3>&, const AxisBox<3>&, bool);
-template bool Contains<2>(const Ball<2>&, const AxisBox<2>&, bool);
-template bool Contains<3>(const Ball<3>&, const AxisBox<3>&, bool);
-
-template bool Intersect<2>(const Ball<2>&, const Ball<2>&, bool);
-template bool Intersect<3>(const Ball<3>&, const Ball<3>&, bool);
-template bool Contains<2>(const Ball<2>&, const Ball<2>&, bool);
-template bool Contains<3>(const Ball<3>&, const Ball<3>&, bool);
-
-template bool Intersect<Point<2>,Segment<2> >(const Point<2>&, const Segment<2>&, bool);
-template bool Intersect<Point<3>,Segment<3> >(const Point<3>&, const Segment<3>&, bool);
-template bool Contains<2>(const Point<2>&, const Segment<2>&, bool);
-template bool Contains<3>(const Point<3>&, const Segment<3>&, bool);
-template bool Intersect<2>(const Segment<2>&, const Point<2>&, bool);
-template bool Intersect<3>(const Segment<3>&, const Point<3>&, bool);
-template bool Contains<2>(const Segment<2>&, const Point<2>&, bool);
-template bool Contains<3>(const Segment<3>&, const Point<3>&, bool);
-
-template bool Intersect<AxisBox<2>,Segment<2> >(const AxisBox<2>&, const Segment<2>&, bool);
-template bool Intersect<AxisBox<3>,Segment<3> >(const AxisBox<3>&, const Segment<3>&, bool);
-template bool Contains<2>(const AxisBox<2>&, const Segment<2>&, bool);
-template bool Contains<3>(const AxisBox<3>&, const Segment<3>&, bool);
-template bool Intersect<2>(const Segment<2>&, const AxisBox<2>&, bool);
-template bool Intersect<3>(const Segment<3>&, const AxisBox<3>&, bool);
-template bool Contains<2>(const Segment<2>&, const AxisBox<2>&, bool);
-template bool Contains<3>(const Segment<3>&, const AxisBox<3>&, bool);
-
-template bool Intersect<Ball<2>,Segment<2> >(const Ball<2>&, const Segment<2>&, bool);
-template bool Intersect<Ball<3>,Segment<3> >(const Ball<3>&, const Segment<3>&, bool);
-template bool Contains<2>(const Ball<2>&, const Segment<2>&, bool);
-template bool Contains<3>(const Ball<3>&, const Segment<3>&, bool);
-template bool Intersect<2>(const Segment<2>&, const Ball<2>&, bool);
-template bool Intersect<3>(const Segment<3>&, const Ball<3>&, bool);
-template bool Contains<2>(const Segment<2>&, const Ball<2>&, bool);
-template bool Contains<3>(const Segment<3>&, const Ball<3>&, bool);
-
-template bool Intersect<2>(const Segment<2>&, const Segment<2>&, bool);
-template bool Intersect<3>(const Segment<3>&, const Segment<3>&, bool);
-template bool Contains<2>(const Segment<2>&, const Segment<2>&, bool);
-template bool Contains<3>(const Segment<3>&, const Segment<3>&, bool);
-
-template bool Intersect<Point<2>,RotBox<2> >(const Point<2>&, const RotBox<2>&, bool);
-template bool Intersect<Point<3>,RotBox<3> >(const Point<3>&, const RotBox<3>&, bool);
-template bool Contains<2>(const Point<2>&, const RotBox<2>&, bool);
-template bool Contains<3>(const Point<3>&, const RotBox<3>&, bool);
-template bool Intersect<2>(const RotBox<2>&, const Point<2>&, bool);
-template bool Intersect<3>(const RotBox<3>&, const Point<3>&, bool);
-template bool Contains<2>(const RotBox<2>&, const Point<2>&, bool);
-template bool Contains<3>(const RotBox<3>&, const Point<3>&, bool);
-
-template bool Intersect<AxisBox<2>,RotBox<2> >(const AxisBox<2>&, const RotBox<2>&, bool);
-template bool Intersect<AxisBox<3>,RotBox<3> >(const AxisBox<3>&, const RotBox<3>&, bool);
-template bool Contains<2>(const AxisBox<2>&, const RotBox<2>&, bool);
-template bool Contains<3>(const AxisBox<3>&, const RotBox<3>&, bool);
-template bool Contains<2>(const RotBox<2>&, const AxisBox<2>&, bool);
-template bool Contains<3>(const RotBox<3>&, const AxisBox<3>&, bool);
-
-template bool Intersect<Ball<2>,RotBox<2> >(const Ball<2>&, const RotBox<2>&, bool);
-template bool Intersect<Ball<3>,RotBox<3> >(const Ball<3>&, const RotBox<3>&, bool);
-template bool Contains<2>(const Ball<2>&, const RotBox<2>&, bool);
-template bool Contains<3>(const Ball<3>&, const RotBox<3>&, bool);
-template bool Intersect<2>(const RotBox<2>&, const Ball<2>&, bool);
-template bool Intersect<3>(const RotBox<3>&, const Ball<3>&, bool);
-template bool Contains<2>(const RotBox<2>&, const Ball<2>&, bool);
-template bool Contains<3>(const RotBox<3>&, const Ball<3>&, bool);
-
-template bool Intersect<Segment<2>,RotBox<2> >(const Segment<2>&, const RotBox<2>&, bool);
-template bool Intersect<Segment<3>,RotBox<3> >(const Segment<3>&, const RotBox<3>&, bool);
-template bool Contains<2>(const Segment<2>&, const RotBox<2>&, bool);
-template bool Contains<3>(const Segment<3>&, const RotBox<3>&, bool);
-template bool Intersect<2>(const RotBox<2>&, const Segment<2>&, bool);
-template bool Intersect<3>(const RotBox<3>&, const Segment<3>&, bool);
-template bool Contains<2>(const RotBox<2>&, const Segment<2>&, bool);
-template bool Contains<3>(const RotBox<3>&, const Segment<3>&, bool);
-
-template bool Intersect<2>(const RotBox<2>&, const RotBox<2>&, bool);
-template bool Intersect<3>(const RotBox<3>&, const RotBox<3>&, bool);
-template bool Contains<2>(const RotBox<2>&, const RotBox<2>&, bool);
-template bool Contains<3>(const RotBox<3>&, const RotBox<3>&, bool);
-
 // The 2d implementation was inspired as a simplification of the 3d.
 // It used the fact that two not-similarly-oriented rectangles a and b
 // intersect each other if and only if a's bounding box in b's coordinate
@@ -359,4 +244,119 @@
   return true;
 }
 
+// force a bunch of instantiations
+
+template bool Intersect<2>(const Point<2>&, const Point<2>&, bool);
+template bool Intersect<3>(const Point<3>&, const Point<3>&, bool);
+template bool Contains<2>(const Point<2>&, const Point<2>&, bool);
+template bool Contains<3>(const Point<3>&, const Point<3>&, bool);
+
+template bool Intersect<Point<2>,AxisBox<2> >(const Point<2>&, const AxisBox<2>&, bool);
+template bool Intersect<Point<3>,AxisBox<3> >(const Point<3>&, const AxisBox<3>&, bool);
+template bool Contains<2>(const Point<2>&, const AxisBox<2>&, bool);
+template bool Contains<3>(const Point<3>&, const AxisBox<3>&, bool);
+template bool Intersect<2>(const AxisBox<2>&, const Point<2>&, bool);
+template bool Intersect<3>(const AxisBox<3>&, const Point<3>&, bool);
+template bool Contains<2>(const AxisBox<2>&, const Point<2>&, bool);
+template bool Contains<3>(const AxisBox<3>&, const Point<3>&, bool);
+
+template bool Intersect<2>(const AxisBox<2>&, const AxisBox<2>&, bool);
+template bool Intersect<3>(const AxisBox<3>&, const AxisBox<3>&, bool);
+template bool Contains<2>(const AxisBox<2>&, const AxisBox<2>&, bool);
+template bool Contains<3>(const AxisBox<3>&, const AxisBox<3>&, bool);
+
+template bool Intersect<Point<2>,Ball<2> >(const Point<2>&, const Ball<2>&, bool);
+template bool Intersect<Point<3>,Ball<3> >(const Point<3>&, const Ball<3>&, bool);
+template bool Contains<2>(const Point<2>&, const Ball<2>&, bool);
+template bool Contains<3>(const Point<3>&, const Ball<3>&, bool);
+template bool Intersect<2>(const Ball<2>&, const Point<2>&, bool);
+template bool Intersect<3>(const Ball<3>&, const Point<3>&, bool);
+template bool Contains<2>(const Ball<2>&, const Point<2>&, bool);
+template bool Contains<3>(const Ball<3>&, const Point<3>&, bool);
+
+template bool Intersect<AxisBox<2>,Ball<2> >(const AxisBox<2>&, const Ball<2>&, bool);
+template bool Intersect<AxisBox<3>,Ball<3> >(const AxisBox<3>&, const Ball<3>&, bool);
+template bool Contains<2>(const AxisBox<2>&, const Ball<2>&, bool);
+template bool Contains<3>(const AxisBox<3>&, const Ball<3>&, bool);
+template bool Intersect<2>(const Ball<2>&, const AxisBox<2>&, bool);
+template bool Intersect<3>(const Ball<3>&, const AxisBox<3>&, bool);
+template bool Contains<2>(const Ball<2>&, const AxisBox<2>&, bool);
+template bool Contains<3>(const Ball<3>&, const AxisBox<3>&, bool);
+
+template bool Intersect<2>(const Ball<2>&, const Ball<2>&, bool);
+template bool Intersect<3>(const Ball<3>&, const Ball<3>&, bool);
+template bool Contains<2>(const Ball<2>&, const Ball<2>&, bool);
+template bool Contains<3>(const Ball<3>&, const Ball<3>&, bool);
+
+template bool Intersect<Point<2>,Segment<2> >(const Point<2>&, const Segment<2>&, bool);
+template bool Intersect<Point<3>,Segment<3> >(const Point<3>&, const Segment<3>&, bool);
+template bool Contains<2>(const Point<2>&, const Segment<2>&, bool);
+template bool Contains<3>(const Point<3>&, const Segment<3>&, bool);
+template bool Intersect<2>(const Segment<2>&, const Point<2>&, bool);
+template bool Intersect<3>(const Segment<3>&, const Point<3>&, bool);
+template bool Contains<2>(const Segment<2>&, const Point<2>&, bool);
+template bool Contains<3>(const Segment<3>&, const Point<3>&, bool);
+
+template bool Intersect<AxisBox<2>,Segment<2> >(const AxisBox<2>&, const Segment<2>&, bool);
+template bool Intersect<AxisBox<3>,Segment<3> >(const AxisBox<3>&, const Segment<3>&, bool);
+template bool Contains<2>(const AxisBox<2>&, const Segment<2>&, bool);
+template bool Contains<3>(const AxisBox<3>&, const Segment<3>&, bool);
+template bool Intersect<2>(const Segment<2>&, const AxisBox<2>&, bool);
+template bool Intersect<3>(const Segment<3>&, const AxisBox<3>&, bool);
+template bool Contains<2>(const Segment<2>&, const AxisBox<2>&, bool);
+template bool Contains<3>(const Segment<3>&, const AxisBox<3>&, bool);
+
+template bool Intersect<Ball<2>,Segment<2> >(const Ball<2>&, const Segment<2>&, bool);
+template bool Intersect<Ball<3>,Segment<3> >(const Ball<3>&, const Segment<3>&, bool);
+template bool Contains<2>(const Ball<2>&, const Segment<2>&, bool);
+template bool Contains<3>(const Ball<3>&, const Segment<3>&, bool);
+template bool Intersect<2>(const Segment<2>&, const Ball<2>&, bool);
+template bool Intersect<3>(const Segment<3>&, const Ball<3>&, bool);
+template bool Contains<2>(const Segment<2>&, const Ball<2>&, bool);
+template bool Contains<3>(const Segment<3>&, const Ball<3>&, bool);
+
+template bool Intersect<2>(const Segment<2>&, const Segment<2>&, bool);
+template bool Intersect<3>(const Segment<3>&, const Segment<3>&, bool);
+template bool Contains<2>(const Segment<2>&, const Segment<2>&, bool);
+template bool Contains<3>(const Segment<3>&, const Segment<3>&, bool);
+
+template bool Intersect<Point<2>,RotBox<2> >(const Point<2>&, const RotBox<2>&, bool);
+template bool Intersect<Point<3>,RotBox<3> >(const Point<3>&, const RotBox<3>&, bool);
+template bool Contains<2>(const Point<2>&, const RotBox<2>&, bool);
+template bool Contains<3>(const Point<3>&, const RotBox<3>&, bool);
+template bool Intersect<2>(const RotBox<2>&, const Point<2>&, bool);
+template bool Intersect<3>(const RotBox<3>&, const Point<3>&, bool);
+template bool Contains<2>(const RotBox<2>&, const Point<2>&, bool);
+template bool Contains<3>(const RotBox<3>&, const Point<3>&, bool);
+
+template bool Intersect<AxisBox<2>,RotBox<2> >(const AxisBox<2>&, const RotBox<2>&, bool);
+template bool Intersect<AxisBox<3>,RotBox<3> >(const AxisBox<3>&, const RotBox<3>&, bool);
+template bool Contains<2>(const AxisBox<2>&, const RotBox<2>&, bool);
+template bool Contains<3>(const AxisBox<3>&, const RotBox<3>&, bool);
+template bool Contains<2>(const RotBox<2>&, const AxisBox<2>&, bool);
+template bool Contains<3>(const RotBox<3>&, const AxisBox<3>&, bool);
+
+template bool Intersect<Ball<2>,RotBox<2> >(const Ball<2>&, const RotBox<2>&, bool);
+template bool Intersect<Ball<3>,RotBox<3> >(const Ball<3>&, const RotBox<3>&, bool);
+template bool Contains<2>(const Ball<2>&, const RotBox<2>&, bool);
+template bool Contains<3>(const Ball<3>&, const RotBox<3>&, bool);
+template bool Intersect<2>(const RotBox<2>&, const Ball<2>&, bool);
+template bool Intersect<3>(const RotBox<3>&, const Ball<3>&, bool);
+template bool Contains<2>(const RotBox<2>&, const Ball<2>&, bool);
+template bool Contains<3>(const RotBox<3>&, const Ball<3>&, bool);
+
+template bool Intersect<Segment<2>,RotBox<2> >(const Segment<2>&, const RotBox<2>&, bool);
+template bool Intersect<Segment<3>,RotBox<3> >(const Segment<3>&, const RotBox<3>&, bool);
+template bool Contains<2>(const Segment<2>&, const RotBox<2>&, bool);
+template bool Contains<3>(const Segment<3>&, const RotBox<3>&, bool);
+template bool Intersect<2>(const RotBox<2>&, const Segment<2>&, bool);
+template bool Intersect<3>(const RotBox<3>&, const Segment<3>&, bool);
+template bool Contains<2>(const RotBox<2>&, const Segment<2>&, bool);
+template bool Contains<3>(const RotBox<3>&, const Segment<3>&, bool);
+
+template bool Intersect<2>(const RotBox<2>&, const RotBox<2>&, bool);
+template bool Intersect<3>(const RotBox<3>&, const RotBox<3>&, bool);
+template bool Contains<2>(const RotBox<2>&, const RotBox<2>&, bool);
+template bool Contains<3>(const RotBox<3>&, const RotBox<3>&, bool);
+
 }
