--- src/fallback.h
+++ src/fallback.h
@@ -200,5 +200,15 @@ int flock(int fd, int op);
 #endif
 
 #ifndef HAVE_WCSTOD_L
-double wcstod_l(const wchar_t *enptr, wchar_t **endptr, locale_t loc);
+// On some platforms if this is incorrectly detected and a system-defined
+// defined version of `wcstod_l` exists, calling `wcstod` from our own
+// `wcstod_l` can call back into `wcstod_l` causing infinite recursion.
+// e.g. FreeBSD defines `wcstod(x, y)` as `wcstod_l(x, y, __get_locale())`.
+// Solution: namespace our implementation to make sure there is no symbol
+// duplication.
+#undef wcstod_l
+namespace fish_compat {
+    double wcstod_l(const wchar_t *enptr, wchar_t **endptr, locale_t loc);
+}
+#define wcstod_l(x, y, z) fish_compat::wcstod_l(x, y, z)
 #endif
