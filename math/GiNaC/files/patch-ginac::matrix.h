--- ginac/matrix.h.orig	Wed Oct  1 01:00:24 2003
+++ ginac/matrix.h	Thu Nov  6 13:30:18 2003
@@ -100,6 +100,7 @@
 	matrix(unsigned r, unsigned c, const exvector & m2);
 	matrix(unsigned r, unsigned c, const lst & l);
 
+#if 0
 	// First step of initialization of matrix with a comma-separated seqeuence
 	// of expressions. Subsequent steps are handled by matrix_init<>::operator,().
 	matrix_init<ex, exvector::iterator> operator=(const ex & x)
@@ -107,6 +108,7 @@
 		m[0] = x;
 		return matrix_init<ex, exvector::iterator>(++m.begin());
 	}
+#endif
 	
 	// functions overriding virtual functions from base classes
 public:
