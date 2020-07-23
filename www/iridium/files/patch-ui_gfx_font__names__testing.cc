--- ui/gfx/font_names_testing.cc.orig	2020-04-06 08:38:05 UTC
+++ ui/gfx/font_names_testing.cc
@@ -22,7 +22,7 @@ Note that we have to support the full range from Jelly
 dessert.
 */
 
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const char kTestFontName[] = "Arimo";
 #elif defined(OS_ANDROID)
 const char kTestFontName[] = "sans-serif";
@@ -30,7 +30,7 @@ const char kTestFontName[] = "sans-serif";
 const char kTestFontName[] = "Arial";
 #endif
 
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const char kSymbolFontName[] = "DejaVu Sans";
 #elif defined(OS_ANDROID)
 const char kSymbolFontName[] = "monospace";
@@ -40,7 +40,7 @@ const char kSymbolFontName[] = "Segoe UI Symbol";
 const char kSymbolFontName[] = "Symbol";
 #endif
 
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const char kCJKFontName[] = "Noto Sans CJK JP";
 #elif defined(OS_ANDROID)
 const char kCJKFontName[] = "serif";
