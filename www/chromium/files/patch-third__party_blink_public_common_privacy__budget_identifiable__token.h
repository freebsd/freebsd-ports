--- third_party/blink/public/common/privacy_budget/identifiable_token.h.orig	2020-11-18 10:21:45 UTC
+++ third_party/blink/public/common/privacy_budget/identifiable_token.h
@@ -118,7 +118,7 @@ class IdentifiableToken {
 
   // Enums. Punt to the underlying type.
   template <typename T,
-            typename U = typename std::underlying_type<T>::type,
+            typename U = typename std::__sfinae_underlying_type<T>::type,
             typename std::enable_if_t<std::is_enum<T>::value>* = nullptr>
   constexpr IdentifiableToken(T in)  // NOLINT(google-explicit-constructor)
       : IdentifiableToken(static_cast<U>(in)) {}
