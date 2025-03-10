--- linbox/matrix/sparsematrix/sparse-ell-matrix.h.orig	2021-12-14 10:16:03 UTC
+++ linbox/matrix/sparsematrix/sparse-ell-matrix.h
@@ -1205,6 +1205,7 @@ namespace LinBox
 				, _row(iter._row)
 			{}
 
+#if 0
 			_IndexedIterator &operator = (const _IndexedIterator &iter)
 			{
 				_colid_beg = iter._colid_beg ;
@@ -1218,6 +1219,7 @@ namespace LinBox
 
 				return *this;
 			}
+#endif
 
 			bool operator == (const _IndexedIterator &i) const
 			{
