--- tensorflow/tsl/framework/type_traits.h.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/tsl/framework/type_traits.h
@@ -91,18 +91,6 @@ class numeric_limits<tsl::qint32> : public numeric_lim
 template <>
 class numeric_limits<tsl::qint32> : public numeric_limits<tsl::int32> {};
 
-// Specialize is_signed for quantized types.
-template <>
-struct is_signed<tsl::qint8> : public is_signed<tsl::int8> {};
-template <>
-struct is_signed<tsl::quint8> : public is_signed<tsl::uint8> {};
-template <>
-struct is_signed<tsl::qint16> : public is_signed<tsl::int16> {};
-template <>
-struct is_signed<tsl::quint16> : public is_signed<tsl::uint16> {};
-template <>
-struct is_signed<tsl::qint32> : public is_signed<tsl::int32> {};
-
 }  // namespace std
 
 #endif  // TENSORFLOW_TSL_FRAMEWORK_TYPE_TRAITS_H_
