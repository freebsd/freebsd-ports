--- src/operators/math/unary.cpp.orig	2023-11-08 01:08:28 UTC
+++ src/operators/math/unary.cpp
@@ -44,7 +44,7 @@ struct LogicalNotOpImpl
 {
   DataT operator()(DataT const& x) const noexcept
   {
-    const auto& b = x != El::TypeTraits<DataT>::Zero() && !std::isnan(x);
+    const auto& b = x != El::TypeTraits<DataT>::Zero() && !internal::isnan(x);
     return !b ? El::TypeTraits<DataT>::One() : El::TypeTraits<DataT>::Zero();
   }
   DataT operator()(DataT const& x, DataT const& /*dy*/) const noexcept
