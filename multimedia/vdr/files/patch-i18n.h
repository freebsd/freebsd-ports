--- i18n.h.orig	2026-06-01 16:59:58 UTC
+++ i18n.h
@@ -46,7 +46,7 @@ const cStringList *I18nLanguages(void);
    ///< have an actual locale installed. The rest are just dummy entries
    ///< to allow having three letter language codes for other languages
    ///< that have no actual locale on this system.
-const char *I18nTranslate(const char *s, const char *Plugin = NULL) __attribute_format_arg__(1);
+const char *I18nTranslate(const char *s, const char *Plugin = NULL) __attribute__((format_arg(1)));
    ///< Translates the given string (with optional Plugin context) into
    ///< the current language. If no translation is available, the original
    ///< string will be returned.
