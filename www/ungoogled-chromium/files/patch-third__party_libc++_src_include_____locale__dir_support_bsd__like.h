--- third_party/libc++/src/include/__locale_dir/support/bsd_like.h.orig	2026-06-05 13:45:06 UTC
+++ third_party/libc++/src/include/__locale_dir/support/bsd_like.h
@@ -61,22 +61,22 @@ inline _LIBCPP_HIDE_FROM_ABI char* __setlocale(int __c
   return ::setlocale(__category, __locale);
 }
 
-inline _LIBCPP_HIDE_FROM_ABI __lconv_t* __localeconv(__locale_t& __loc) { return ::localeconv_l(__loc); }
+inline _LIBCPP_HIDE_FROM_ABI __lconv_t* __localeconv(__locale_t& __loc) { return ::localeconv(); }
 #endif // _LIBCPP_BUILDING_LIBRARY
 
 //
 // Strtonum functions
 //
 inline _LIBCPP_HIDE_FROM_ABI float __strtof(const char* __nptr, char** __endptr, __locale_t __loc) {
-  return ::strtof_l(__nptr, __endptr, __loc);
+  return ::strtof(__nptr, __endptr);
 }
 
 inline _LIBCPP_HIDE_FROM_ABI double __strtod(const char* __nptr, char** __endptr, __locale_t __loc) {
-  return ::strtod_l(__nptr, __endptr, __loc);
+  return ::strtod(__nptr, __endptr);
 }
 
 inline _LIBCPP_HIDE_FROM_ABI long double __strtold(const char* __nptr, char** __endptr, __locale_t __loc) {
-  return ::strtold_l(__nptr, __endptr, __loc);
+  return ::strtold(__nptr, __endptr);
 }
 
 //
@@ -141,43 +141,43 @@ inline _LIBCPP_HIDE_FROM_ABI _LIBCPP_ATTRIBUTE_FORMAT(
 //
 // Other functions
 //
-inline _LIBCPP_HIDE_FROM_ABI decltype(MB_CUR_MAX) __mb_len_max(__locale_t __loc) { return MB_CUR_MAX_L(__loc); }
+inline _LIBCPP_HIDE_FROM_ABI decltype(MB_CUR_MAX) __mb_len_max(__locale_t __loc) { return MB_CUR_MAX; }
 
 #  if _LIBCPP_HAS_WIDE_CHARACTERS
-inline _LIBCPP_HIDE_FROM_ABI wint_t __btowc(int __c, __locale_t __loc) { return ::btowc_l(__c, __loc); }
+inline _LIBCPP_HIDE_FROM_ABI wint_t __btowc(int __c, __locale_t __loc) { return ::btowc(__c); }
 
-inline _LIBCPP_HIDE_FROM_ABI int __wctob(wint_t __c, __locale_t __loc) { return ::wctob_l(__c, __loc); }
+inline _LIBCPP_HIDE_FROM_ABI int __wctob(wint_t __c, __locale_t __loc) { return ::wctob(__c); }
 
 inline _LIBCPP_HIDE_FROM_ABI size_t
 __wcsnrtombs(char* __dest, const wchar_t** __src, size_t __nwc, size_t __len, mbstate_t* __ps, __locale_t __loc) {
-  return ::wcsnrtombs_l(__dest, __src, __nwc, __len, __ps, __loc); // wcsnrtombs is a POSIX extension
+  return ::wcsnrtombs(__dest, __src, __nwc, __len, __ps); // wcsnrtombs is a POSIX extension
 }
 
 inline _LIBCPP_HIDE_FROM_ABI size_t __wcrtomb(char* __s, wchar_t __wc, mbstate_t* __ps, __locale_t __loc) {
-  return ::wcrtomb_l(__s, __wc, __ps, __loc);
+  return ::wcrtomb(__s, __wc, __ps);
 }
 
 inline _LIBCPP_HIDE_FROM_ABI size_t
 __mbsnrtowcs(wchar_t* __dest, const char** __src, size_t __nms, size_t __len, mbstate_t* __ps, __locale_t __loc) {
-  return ::mbsnrtowcs_l(__dest, __src, __nms, __len, __ps, __loc); // mbsnrtowcs is a POSIX extension
+  return ::mbsnrtowcs(__dest, __src, __nms, __len, __ps); // mbsnrtowcs is a POSIX extension
 }
 
 inline _LIBCPP_HIDE_FROM_ABI size_t
 __mbrtowc(wchar_t* __pwc, const char* __s, size_t __n, mbstate_t* __ps, __locale_t __loc) {
-  return ::mbrtowc_l(__pwc, __s, __n, __ps, __loc);
+  return ::mbrtowc(__pwc, __s, __n, __ps);
 }
 
 inline _LIBCPP_HIDE_FROM_ABI int __mbtowc(wchar_t* __pwc, const char* __pmb, size_t __max, __locale_t __loc) {
-  return ::mbtowc_l(__pwc, __pmb, __max, __loc);
+  return ::mbtowc(__pwc, __pmb, __max);
 }
 
 inline _LIBCPP_HIDE_FROM_ABI size_t __mbrlen(const char* __s, size_t __n, mbstate_t* __ps, __locale_t __loc) {
-  return ::mbrlen_l(__s, __n, __ps, __loc);
+  return ::mbrlen(__s, __n, __ps);
 }
 
 inline _LIBCPP_HIDE_FROM_ABI size_t
 __mbsrtowcs(wchar_t* __dest, const char** __src, size_t __len, mbstate_t* __ps, __locale_t __loc) {
-  return ::mbsrtowcs_l(__dest, __src, __len, __ps, __loc);
+  return ::mbsrtowcs(__dest, __src, __len, __ps);
 }
 #  endif // _LIBCPP_HAS_WIDE_CHARACTERS
 #endif   // _LIBCPP_BUILDING_LIBRARY
@@ -194,13 +194,13 @@ _LIBCPP_GCC_DIAGNOSTIC_IGNORED("-Wformat-nonliteral") 
 template <class... _Args>
 _LIBCPP_HIDE_FROM_ABI _LIBCPP_VARIADIC_ATTRIBUTE_FORMAT(__printf__, 4, 5) int __snprintf(
     char* __s, size_t __n, __locale_t __loc, const char* __format, _Args&&... __args) {
-  return ::snprintf_l(__s, __n, __loc, __format, std::forward<_Args>(__args)...);
+  return ::snprintf(__s, __n, __format, std::forward<_Args>(__args)...);
 }
 
 template <class... _Args>
 _LIBCPP_HIDE_FROM_ABI _LIBCPP_VARIADIC_ATTRIBUTE_FORMAT(__printf__, 3, 4) int __asprintf(
     char** __s, __locale_t __loc, const char* __format, _Args&&... __args) {
-  return ::asprintf_l(__s, __loc, __format, std::forward<_Args>(__args)...); // non-standard
+  return ::asprintf(__s, __format, std::forward<_Args>(__args)...); // non-standard
 }
 _LIBCPP_DIAGNOSTIC_POP
 #undef _LIBCPP_VARIADIC_ATTRIBUTE_FORMAT
