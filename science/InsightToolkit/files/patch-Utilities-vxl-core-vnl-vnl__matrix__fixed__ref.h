--- Utilities/vxl/core/vnl/vnl_matrix_fixed_ref.h.orig	2006-03-22 01:25:06.000000000 +0300
+++ Utilities/vxl/core/vnl/vnl_matrix_fixed_ref.h	2013-12-17 17:21:57.529194289 +0400
@@ -653,7 +653,7 @@
   //: Return true if *this == rhs
   bool operator_eq (vnl_matrix_fixed_ref_const<T,num_rows,num_cols> const & rhs) const
   {
-    return equal( this->data_block(), rhs.data_block() );
+    return this->equal( this->data_block(), rhs.data_block() );
   }
 
   //: Equality operator
