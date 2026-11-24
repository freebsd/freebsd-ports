--- src/support/debug.h	2026-09-07 18:54:34 UTC
+++ src/support/debug.h
@@ -216,6 +216,11 @@ extern LyXErr lyxerr;
 
 extern LyXErr lyxerr;
 
+/// Make \p os convert the UTF-8 text written to it into the character
+/// set of the current locale (LC_CTYPE). Does nothing if that character
+/// set is UTF-8 already, or if the locale is "C" or "POSIX".
+void transcodeToLocale(std::ostream & os);
+
 } // namespace lyx
 
 #define CURRENT_POSITION lyx::LyXErr::stripName(__FILE__) << " (" << __LINE__ << "): "
