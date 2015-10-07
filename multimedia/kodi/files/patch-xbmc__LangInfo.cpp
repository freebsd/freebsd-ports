--- xbmc/LangInfo.cpp.orig	2015-07-21 18:41:29 UTC
+++ xbmc/LangInfo.cpp
@@ -275,8 +275,8 @@
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
