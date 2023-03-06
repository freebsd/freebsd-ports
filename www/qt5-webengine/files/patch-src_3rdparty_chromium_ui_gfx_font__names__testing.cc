--- src/3rdparty/chromium/ui/gfx/font_names_testing.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/gfx/font_names_testing.cc
@@ -22,7 +22,7 @@ dessert.
 dessert.
 */
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const char kTestFontName[] = "Arimo";
 #elif defined(OS_ANDROID)
 const char kTestFontName[] = "sans-serif";
@@ -30,7 +30,7 @@ const char kTestFontName[] = "Arial";
 const char kTestFontName[] = "Arial";
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const char kSymbolFontName[] = "DejaVu Sans";
 #elif defined(OS_ANDROID)
 const char kSymbolFontName[] = "monospace";
@@ -40,7 +40,7 @@ const char kSymbolFontName[] = "Symbol";
 const char kSymbolFontName[] = "Symbol";
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const char kCJKFontName[] = "Noto Sans CJK JP";
 #elif defined(OS_ANDROID)
 const char kCJKFontName[] = "serif";
