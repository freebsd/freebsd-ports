--- vendor/kazhdan/SparseMatrix.h.orig	2024-06-29 01:37:43 UTC
+++ vendor/kazhdan/SparseMatrix.h
@@ -67,8 +67,6 @@ template<class T> class SparseMatrix (public)
 	SparseMatrix( const SparseMatrix& M );
 	~SparseMatrix();
 
-	void SetZero();
-
 	SparseMatrix<T>& operator = (const SparseMatrix<T>& M);
 
 	SparseMatrix<T> operator * (const T& V) const;
