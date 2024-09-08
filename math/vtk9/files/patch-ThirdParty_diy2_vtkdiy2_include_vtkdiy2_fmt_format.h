--- ThirdParty/diy2/vtkdiy2/include/vtkdiy2/fmt/format.h.orig	2023-02-15 04:03:53 UTC
+++ ThirdParty/diy2/vtkdiy2/include/vtkdiy2/fmt/format.h
@@ -480,6 +480,7 @@ void buffer<T>::append(const U* begin, const U* end) {
 }
 }  // namespace internal
 
+#ifdef __cpp_char8_t
 // A UTF-8 string view.
 class u8string_view : public basic_string_view<char8_t> {
  public:
@@ -497,6 +498,7 @@ inline u8string_view operator"" _u(const char* s, std:
 }
 }  // namespace literals
 #endif
+#endif // __cpp_char8_t
 
 // The number of characters to store in the basic_memory_buffer object itself
 // to avoid dynamic memory allocation.
