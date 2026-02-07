--- lib/core/include/GenericMatrix.h.orig	2024-09-24 09:32:47 UTC
+++ lib/core/include/GenericMatrix.h
@@ -1525,12 +1525,12 @@ class ConcatRows< BlockMatrix<MatrixList, std::true_ty
    template <size_t i>
    decltype(auto) get_container(size_constant<i>)
    {
-      return concat_rows(this->hidden().template get_container(size_constant<i>()));
+      return concat_rows(this->hidden().get_container(size_constant<i>()));
    }
    template <size_t i>
    decltype(auto) get_container(size_constant<i>) const
    {
-      return concat_rows(this->hidden().template get_container(size_constant<i>()));
+      return concat_rows(this->hidden().get_container(size_constant<i>()));
    }
 
    ConcatRows& operator= (const ConcatRows& other) { return ConcatRows::generic_type::operator=(other); }
