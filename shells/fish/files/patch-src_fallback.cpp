--- src/fallback.cpp
+++ src/fallback.cpp
@@ -390,9 +390,10 @@ int flock(int fd, int op) {
 #endif  // HAVE_FLOCK
 
 #ifndef HAVE_WCSTOD_L
-// musl doesn't feature wcstod_l,
-// so we just wrap wcstod.
-double wcstod_l(const wchar_t *enptr, wchar_t **endptr, locale_t loc) {
+#undef wcstod_l
+// For platforms without wcstod_l C extension, wrap wcstod after changing the
+// thread-specific locale.
+double fish_compat::wcstod_l(const wchar_t *enptr, wchar_t **endptr, locale_t loc) {
     char *saved_locale = strdup(setlocale(LC_NUMERIC, NULL));
     // Yes, this is hardcoded to use the "C" locale.
     // That's the only thing we need, and uselocale(loc) broke in my testing.
