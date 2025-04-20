--- src/lib/geogram/third_party/PoissonRecon/SparseMatrix.inl.orig	2024-06-14 05:04:18 UTC
+++ src/lib/geogram/third_party/PoissonRecon/SparseMatrix.inl
@@ -191,11 +191,15 @@ void SparseMatrix< T >::SetRowSize( int row , int coun
 }
 
 
+/*
+//[Bruno] 11/09/2024 commented-out (m_M, m_N do not exist, breaks
+// clang-19 compile
 template<class T>
 void SparseMatrix<T>::SetZero()
 {
         Resize(this->m_N, this->m_M);
 }
+*/
 
 template<class T>
 SparseMatrix<T> SparseMatrix<T>::operator * (const T& V) const
