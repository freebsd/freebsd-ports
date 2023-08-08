--- src/intl/gettext/libintl.h.orig	2022-12-25 18:17:02 UTC
+++ src/intl/gettext/libintl.h
@@ -44,7 +44,7 @@ _(const char *msg, struct terminal *term)
 	return (char *)gettext_noop(msg);
 }
 
-static inline char *
+static inline const char *
 n_(const char *msg1, const char *msg2, unsigned long int n, struct terminal *term)
 {
 	return (char *)gettext_noop(msg1);
