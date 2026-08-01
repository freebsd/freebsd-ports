--- src/operators/math/binary.cpp.orig	2023-11-08 01:08:28 UTC
+++ src/operators/math/binary.cpp
@@ -395,8 +395,8 @@ struct LogicalAndOpImpl
 {
   DataT operator()(DataT const& x1, DataT const& x2) const noexcept
   {
-    bool const b1 = x1 != El::TypeTraits<DataT>::Zero() && !std::isnan(x1);
-    bool const b2 = x2 != El::TypeTraits<DataT>::Zero() && !std::isnan(x2);
+    bool const b1 = x1 != El::TypeTraits<DataT>::Zero() && !internal::isnan(x1);
+    bool const b2 = x2 != El::TypeTraits<DataT>::Zero() && !internal::isnan(x2);
     return (b1 && b2) ? El::TypeTraits<DataT>::One()
                       : El::TypeTraits<DataT>::Zero();
   }
@@ -417,8 +417,8 @@ struct LogicalOrOpImpl
 {
   DataT operator()(DataT const& x1, DataT const& x2) const noexcept
   {
-    bool const b1 = x1 != El::TypeTraits<DataT>::Zero() && !std::isnan(x1);
-    bool const b2 = x2 != El::TypeTraits<DataT>::Zero() && !std::isnan(x2);
+    bool const b1 = x1 != El::TypeTraits<DataT>::Zero() && !internal::isnan(x1);
+    bool const b2 = x2 != El::TypeTraits<DataT>::Zero() && !internal::isnan(x2);
     return (b1 || b2) ? El::TypeTraits<DataT>::One()
                       : El::TypeTraits<DataT>::Zero();
   }
@@ -439,8 +439,8 @@ struct LogicalXorOpImpl
 {
   DataT operator()(DataT const& x1, DataT const& x2) const noexcept
   {
-    bool const b1 = x1 != El::TypeTraits<DataT>::Zero() && !std::isnan(x1);
-    bool const b2 = x2 != El::TypeTraits<DataT>::Zero() && !std::isnan(x2);
+    bool const b1 = x1 != El::TypeTraits<DataT>::Zero() && !internal::isnan(x1);
+    bool const b2 = x2 != El::TypeTraits<DataT>::Zero() && !internal::isnan(x2);
     return (b1 || b2) && !(b1 && b2) ? El::TypeTraits<DataT>::One()
                                      : El::TypeTraits<DataT>::Zero();
   }
