--- src/3rdparty/chromium/third_party/pdfium/third_party/base/template_util.h.orig	2023-11-09 11:32:20 UTC
+++ src/3rdparty/chromium/third_party/pdfium/third_party/base/template_util.h
@@ -109,24 +109,8 @@ struct is_iterator<T,
 
 // TODO(crbug.com/554293): Remove this when all platforms have this in the std
 // namespace and it works with gcc as needed.
-#if defined(CR_USE_FALLBACKS_FOR_OLD_EXPERIMENTAL_GLIBCXX) || \
-    defined(CR_USE_FALLBACKS_FOR_GCC_WITH_LIBCXX)
-template <typename T>
-struct is_trivially_copyable {
-// TODO(danakj): Remove this when android builders are all using a newer version
-// of gcc, or the android ndk is updated to a newer libc++ that does this for
-// us.
-#if _GNUC_VER >= 501
-  static constexpr bool value = __is_trivially_copyable(T);
-#else
-  static constexpr bool value =
-      __has_trivial_copy(T) && __has_trivial_destructor(T);
-#endif
-};
-#else
 template <class T>
 using is_trivially_copyable = std::is_trivially_copyable<T>;
-#endif
 
 #if defined(__GNUC__) && !defined(__clang__) && __GNUC__ <= 7
 // Workaround for g++7 and earlier family.
