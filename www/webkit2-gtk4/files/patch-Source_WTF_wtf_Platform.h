Fix build with icu4c >=69.1

Index: Source/WTF/wtf/Platform.h
--- Source/WTF/wtf/Platform.h.orig
+++ Source/WTF/wtf/Platform.h
@@ -113,7 +113,6 @@
 
 /* FIXME: This does not belong in Platform.h and should instead be included in another mechanism (compiler option, prefix header, config.h, etc) */
 /* ICU configuration. Some of these match ICU defaults on some platforms, but we would like them consistently set everywhere we build WebKit. */
-#define U_HIDE_DEPRECATED_API 1
 #define U_SHOW_CPLUSPLUS_API 0
 #ifdef __cplusplus
 #define UCHAR_TYPE char16_t
