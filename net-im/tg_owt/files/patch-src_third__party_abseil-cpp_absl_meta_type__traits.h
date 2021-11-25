--- src/third_party/abseil-cpp/absl/meta/type_traits.h.orig	2021-10-21 06:15:41 UTC
+++ src/third_party/abseil-cpp/absl/meta/type_traits.h
@@ -616,19 +616,14 @@ using common_type_t = typename std::common_type<T...>:
 template <typename T>
 using underlying_type_t = typename std::underlying_type<T>::type;
 
-#if _MSVC_LANG > 201703L
-template <typename T>
-struct result_of_helper;
-template <typename F, typename ...Args>
-struct result_of_helper<F(Args...)> {
-  using type = std::invoke_result_t<F, Args...>;
-};
-template <typename T>
-using result_of_t = typename result_of_helper<T>::type;
-#else   // C++20
-template <typename T>
-using result_of_t = typename std::result_of<T>::type;
-#endif  // C++20
+#if __cplusplus >= 201703L || (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L)
+// std::result_of is deprecated (C++17) or removed (C++20)
+template<typename> struct result_of;
+template<typename F, typename... Args>
+struct result_of<F(Args...)> : std::invoke_result<F, Args...> {};
+#else
+template<typename F> using result_of = std::result_of<F>;
+#endif
 
 namespace type_traits_internal {
 // In MSVC we can't probe std::hash or stdext::hash because it triggers a
