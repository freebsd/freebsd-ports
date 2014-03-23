--- wfmath/rotbox.h.orig	2014-03-10 19:19:38.000000000 +0100
+++ wfmath/rotbox.h	2014-03-10 19:19:56.000000000 +0100
@@ -159,6 +159,9 @@
   RotBox toParentCoords(const Point<dim>& origin, const Quaternion& rotation) const;
   RotBox toLocalCoords(const Point<dim>& origin, const Quaternion& rotation) const;
 
+  friend bool Intersect<2>(const RotBox<2>& r, const AxisBox<2>& b, bool proper);
+  friend bool Intersect<3>(const RotBox<3>& r, const AxisBox<3>& b, bool proper);
+
   friend bool Intersect<dim>(const RotBox& r, const Point<dim>& p, bool proper);
   friend bool Contains<dim>(const Point<dim>& p, const RotBox& r, bool proper);
 
@@ -181,8 +184,6 @@
   friend bool Contains<dim>(const Polygon<dim>& p, const RotBox& r, bool proper);
   friend bool Contains<dim>(const RotBox& r, const Polygon<dim>& p, bool proper);
 
- private:
-
   Point<dim> m_corner0;
   Vector<dim> m_size;
   RotMatrix<dim> m_orient;
