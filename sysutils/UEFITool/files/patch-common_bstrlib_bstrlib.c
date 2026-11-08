--- common/bstrlib/bstrlib.c.orig	2026-10-27 08:13:46 UTC
+++ common/bstrlib/bstrlib.c
@@ -2918,7 +2918,7 @@
 #define START_VSNBUFF (256)
 #else
 
-#if defined(__GNUC__) && !defined(__APPLE__)
+#if defined(__GNUC__) && !defined(__APPLE__) && !defined(vsnprintf)
 /* Something is making gcc complain about this prototype not being here, so
    I've just gone ahead and put it in. */
 extern int vsnprintf (char *buf, size_t count, const char *format, va_list arg);
