--- vendor/kazhdan/SparseMatrix.inl.orig	2024-06-29 01:37:43 UTC
+++ vendor/kazhdan/SparseMatrix.inl
@@ -188,13 +188,6 @@ void SparseMatrix< T >::SetRowSize( int row , int coun
     }
 }
 
-
-template<class T>
-void SparseMatrix<T>::SetZero()
-{
-    Resize(this->m_N, this->m_M);
-}
-
 template<class T>
 SparseMatrix<T> SparseMatrix<T>::operator * (const T& V) const
 {
