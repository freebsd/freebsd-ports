--- linbox/vector/blas-subvector.h.orig	2021-12-14 10:16:03 UTC
+++ linbox/vector/blas-subvector.h
@@ -117,8 +117,10 @@ namespace LinBox {
          * \param dim dimension
          * \param inc distance between two element
          */
+#if 0
         BlasSubvector (Self_t &V, size_t beg, size_t inc, size_t dim) :
             _ptr(V.data()+beg), _size(dim), _inc(inc), _field(&V.field()) {}
+#endif
 
         
         /** Constructor from an existing @ref BlasVector
