--- common/debug.h.orig	2017-06-16 14:55:26 UTC
+++ common/debug.h
@@ -144,6 +144,10 @@ void              p11_debug_precond             (const
 
 #else /* !defined (WITH_DEBUG) */
 
+#undef p11_debug
+#define p11_debug(format, ...) \
+	do {} while (false)
+
 #undef p11_debug_err
 #define p11_debug_err(errnum, format, ...) \
 	do {} while (false)
