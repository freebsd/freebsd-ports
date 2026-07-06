-- Suppress -Winvalid-specialization for the std::is_pod, std::is_floating_point,
-- std::is_signed, and std::is_unsigned specializations. Clang 17+ treats user
-- specializations of these standard library type traits as an error. Wrap them
-- in pragma diagnostic push/pop to preserve the intended behavior while
-- suppressing the diagnostic.
--- paddle/phi/common/complex.h.orig	2026-06-19 17:50:07 UTC
+++ paddle/phi/common/complex.h
@@ -686,6 +686,14 @@ namespace std {
 
 namespace std {
 
+// Clang 17+ disallows specialization of is_pod, is_floating_point, is_signed,
+// and is_unsigned. Suppress the diagnostic for these PaddlePaddle-specific
+// specializations.
+#if defined(__clang__)
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Winvalid-specialization"
+#endif
+
 template <typename T>
 struct is_pod<phi::dtype::complex<T>> {
   static const bool value = true;
@@ -704,6 +712,10 @@ struct is_unsigned<phi::dtype::complex<T>> {
 struct is_unsigned<phi::dtype::complex<T>> {
   static const bool value = false;
 };
+
+#if defined(__clang__)
+#pragma clang diagnostic pop
+#endif
 
 template <typename T>
 inline bool isnan(const phi::dtype::complex<T>& a) {
