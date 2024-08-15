--- memory/mozalloc/throw_gcc.h.orig	2022-03-05 00:14:41 UTC
+++ memory/mozalloc/throw_gcc.h
@@ -74,50 +74,66 @@ __throw_bad_function_call(void) {
   mozalloc_abort("fatal: STL threw bad_function_call");
 }
 
+#if !defined(_LIBCPP_VERSION)
 MOZ_THROW_NORETURN MOZ_THROW_EXPORT MOZ_THROW_INLINE void __throw_logic_error(
     const char* msg) {
   mozalloc_abort(msg);
 }
+#endif  // _LIBCPP_VERSION
 
+#if !defined(_LIBCPP_VERSION)
 MOZ_THROW_NORETURN MOZ_THROW_EXPORT MOZ_THROW_INLINE void __throw_domain_error(
     const char* msg) {
   mozalloc_abort(msg);
 }
+#endif  // _LIBCPP_VERSION
 
+#if !defined(_LIBCPP_VERSION)
 MOZ_THROW_NORETURN MOZ_THROW_EXPORT MOZ_THROW_INLINE void
 __throw_invalid_argument(const char* msg) {
   mozalloc_abort(msg);
 }
+#endif  // _LIBCPP_VERSION
 
+#if !defined(_LIBCPP_VERSION)
 MOZ_THROW_NORETURN MOZ_THROW_EXPORT MOZ_THROW_INLINE void __throw_length_error(
     const char* msg) {
   mozalloc_abort(msg);
 }
+#endif  // _LIBCPP_VERSION
 
+#if !defined(_LIBCPP_VERSION)
 MOZ_THROW_NORETURN MOZ_THROW_EXPORT MOZ_THROW_INLINE void __throw_out_of_range(
     const char* msg) {
   mozalloc_abort(msg);
 }
+#endif  // _LIBCPP_VERSION
 
 MOZ_THROW_NORETURN MOZ_THROW_EXPORT MOZ_THROW_INLINE void __throw_runtime_error(
     const char* msg) {
   mozalloc_abort(msg);
 }
 
+#if !defined(_LIBCPP_VERSION)
 MOZ_THROW_NORETURN MOZ_THROW_EXPORT MOZ_THROW_INLINE void __throw_range_error(
     const char* msg) {
   mozalloc_abort(msg);
 }
+#endif  // _LIBCPP_VERSION
 
+#if !defined(_LIBCPP_VERSION)
 MOZ_THROW_NORETURN MOZ_THROW_EXPORT MOZ_THROW_INLINE void
 __throw_overflow_error(const char* msg) {
   mozalloc_abort(msg);
 }
+#endif  // _LIBCPP_VERSION
 
+#if !defined(_LIBCPP_VERSION)
 MOZ_THROW_NORETURN MOZ_THROW_EXPORT MOZ_THROW_INLINE void
 __throw_underflow_error(const char* msg) {
   mozalloc_abort(msg);
 }
+#endif  // _LIBCPP_VERSION
 
 MOZ_THROW_NORETURN MOZ_THROW_EXPORT MOZ_THROW_INLINE void __throw_ios_failure(
     const char* msg) {
