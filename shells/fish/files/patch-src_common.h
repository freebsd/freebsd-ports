--- src/common.h.orig	2018-01-26 20:48:40 UTC
+++ src/common.h
@@ -658,7 +658,7 @@ wcstring vformat_string(const wchar_t *format, va_list
 void append_format(wcstring &str, const wchar_t *format, ...);
 void append_formatv(wcstring &str, const wchar_t *format, va_list ap);
 
-#ifdef __cpp_lib_make_unique
+#if __cplusplus >= 201402L
 using std::make_unique;
 #else
 /// make_unique implementation
