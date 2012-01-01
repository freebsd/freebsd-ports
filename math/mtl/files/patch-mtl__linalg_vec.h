--- mtl/linalg_vec.h.orig	2007-04-10 16:03:10.000000000 -0400
+++ mtl/linalg_vec.h	2012-01-01 06:06:12.000000000 -0500
@@ -116,6 +116,7 @@
   typedef difference_type Vec_difference_type;
   typedef iterator Vec_iterator;
   typedef const_iterator Vec_const_iterator;
+  typedef value_type Vec_value_type;
 
   class IndexArray {
   public:
