--- xbmc/LangInfo.cpp.orig	2017-11-14 16:55:01 UTC
+++ xbmc/LangInfo.cpp
@@ -284,8 +284,8 @@ void CLangInfo::CRegion::SetGlobalLocale()
   // decimal separator is changed depending of the current language
   // (ie. "," in French or Dutch instead of "."). This breaks atof() and
   // others similar functions.
-#if defined(TARGET_FREEBSD) || defined(TARGET_DARWIN_OSX) || defined(__UCLIBC__)
-  // on FreeBSD, darwin and uClibc-based systems libstdc++ is compiled with
+#if defined(TARGET_DARWIN_OSX) || defined(__UCLIBC__)
+  // on darwin and uClibc-based systems libstdc++ is compiled with
   // "generic" locale support
   if (setlocale(LC_COLLATE, strLocale.c_str()) == NULL
   || setlocale(LC_CTYPE, strLocale.c_str()) == NULL)
