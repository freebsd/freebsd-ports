--- FIXES/sort.cc.orig	Wed Sep  1 21:41:41 2004
+++ FIXES/sort.cc	Wed Sep  1 21:43:18 2004
@@ -87,8 +87,8 @@
   return (a->vec < b->vec);
 }
 
-template octave_sort<unsigned EIGHT_BYTE_INT>;
-template octave_sort<vec_index *>;
+template class octave_sort<unsigned EIGHT_BYTE_INT>;
+template class octave_sort<vec_index *>;
 #else
 struct vec_index
 {
@@ -124,7 +124,7 @@
   return (xisnan(b->vec) || (abs(a->vec) < abs(b->vec)));
 }
 
-template octave_sort<complex_vec_index *>;
+template class octave_sort<complex_vec_index *>;
 
 static octave_value_list
 vec_sort (RowVector &vec, bool return_idx)
