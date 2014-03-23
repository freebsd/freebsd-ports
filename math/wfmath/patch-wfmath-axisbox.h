--- wfmath/axisbox.h.orig	2014-03-10 19:19:47.000000000 +0100
+++ wfmath/axisbox.h	2014-03-10 19:20:00.000000000 +0100
@@ -153,6 +153,9 @@
   /// Get the minimal box that contains a1 and a2
   friend AxisBox Union<dim>(const AxisBox& a1, const AxisBox& a2);
 
+  friend bool Intersect<2>(const RotBox<2>& r, const AxisBox<2>& b, bool proper);
+  friend bool Intersect<3>(const RotBox<3>& r, const AxisBox<3>& b, bool proper);
+
   friend bool Intersect<dim>(const AxisBox& b, const Point<dim>& p, bool proper);
   friend bool Contains<dim>(const Point<dim>& p, const AxisBox& b, bool proper);
 
@@ -174,8 +177,6 @@
   friend bool Contains<dim>(const Polygon<dim>& p, const AxisBox& b, bool proper);
   friend bool Contains<dim>(const AxisBox& b, const Polygon<dim>& p, bool proper);
 
- private:
-
   Point<dim> m_low, m_high;
 };
 
