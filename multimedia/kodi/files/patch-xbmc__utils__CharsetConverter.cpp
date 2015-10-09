--- xbmc/utils/CharsetConverter.cpp.orig	2015-08-10 08:41:28 UTC
+++ xbmc/utils/CharsetConverter.cpp
@@ -67,7 +67,7 @@
   #define UTF16_CHARSET "UTF-16" ENDIAN_SUFFIX
   #define UTF32_CHARSET "UTF-32" ENDIAN_SUFFIX
   #define UTF8_SOURCE "UTF-8"
-  #define WCHAR_CHARSET "WCHAR_T"
+  #define WCHAR_CHARSET UTF32_CHARSET
   #if __STDC_ISO_10646__
     #ifdef SIZEOF_WCHAR_T
       #if SIZEOF_WCHAR_T == 4
