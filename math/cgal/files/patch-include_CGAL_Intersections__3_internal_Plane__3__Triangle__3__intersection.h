--- include/CGAL/Intersections_3/internal/Plane_3_Triangle_3_intersection.h.orig	2024-03-04 16:56:49 UTC
+++ include/CGAL/Intersections_3/internal/Plane_3_Triangle_3_intersection.h
@@ -13,6 +13,12 @@
 #ifndef CGAL_INTERNAL_INTERSECTIONS_PLANE_3_TRIANGLE_3_INTERSECTION_H
 #define CGAL_INTERNAL_INTERSECTIONS_PLANE_3_TRIANGLE_3_INTERSECTION_H
 
+#include <boost/version.hpp>
+#if BOOST_VERSION >= 106700
+#include <boost/next_prior.hpp>
+#else
+#include <boost/utility.hpp>
+#endif
 #include <CGAL/Intersection_traits_3.h>
 #include <CGAL/Intersections_3/internal/Line_3_Plane_3_intersection.h>
 
