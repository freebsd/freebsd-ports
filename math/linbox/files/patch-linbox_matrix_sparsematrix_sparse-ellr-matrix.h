--- linbox/matrix/sparsematrix/sparse-ellr-matrix.h.orig	2021-12-14 10:16:03 UTC
+++ linbox/matrix/sparsematrix/sparse-ellr-matrix.h
@@ -1099,6 +1099,7 @@ namespace LinBox
 
 			{}
 
+#if 0
 			_Iterator &operator = (const _Iterator &iter)
 			{
 				_data_it  = iter._data_it  ;
@@ -1111,6 +1112,7 @@ namespace LinBox
 
 				return *this;
 			}
+#endif
 
 			bool operator == (const _Iterator &i) const
 			{
@@ -1246,6 +1248,7 @@ namespace LinBox
 				, _row(iter._row)
 			{}
 
+#if 0
 			_IndexedIterator &operator = (const _IndexedIterator &iter)
 			{
 				_rowid_it  = iter._rowid_it ;
@@ -1260,6 +1263,7 @@ namespace LinBox
 
 				return *this;
 			}
+#endif
 
 			bool operator == (const _IndexedIterator &i) const
 			{
