--- src/3rdparty/chromium/base/metrics/histogram_macros_internal.h.orig	2025-04-23 16:00:55 UTC
+++ src/3rdparty/chromium/base/metrics/histogram_macros_internal.h
@@ -42,6 +42,10 @@ struct EnumSizeTraits<
     Enum,
     std::enable_if_t<std::is_enum<decltype(Enum::kMaxValue)>::value>> {
   static constexpr Enum Count() {
+    // If you're getting
+    //   note: integer value X is outside the valid range of values [0, X] for
+    //         this enumeration type
+    // Then you need to give your enum a fixed underlying type.
     return static_cast<Enum>(
         static_cast<std::underlying_type_t<Enum>>(Enum::kMaxValue) + 1);
   }
