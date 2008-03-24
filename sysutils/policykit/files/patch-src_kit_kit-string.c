--- src/kit/kit-string.c.orig	2007-12-23 00:42:03.000000000 -0500
+++ src/kit/kit-string.c	2007-12-23 00:41:26.000000000 -0500
@@ -77,7 +77,15 @@ kit_strdup (const char *s)
 out:
         return p;
 }
+#else /* !KIT_BUILD_TESTS */
+char *
+kit_strdup (const char *s)
+{
+        return strdup (s);
+}
+#endif /* KIT_BUILD_TESTS */
 
+#if defined(KIT_BUILD_TESTS) || !defined(HAVE_STRNDUP)
 /**
  * kit_strndup:
  * @s: string
@@ -111,13 +119,7 @@ out:
         return p;
 }
 
-#else
-
-char *
-kit_strdup (const char *s)
-{
-        return strdup (s);
-}
+#else /* !KIT_BUILD_TESTS || HAVE_STRNDUP */
 
 char *
 kit_strndup (const char *s, size_t n)
@@ -125,7 +127,7 @@ kit_strndup (const char *s, size_t n)
         return strndup (s, n);
 }
 
-#endif /* KIT_BUILD_TESTS */
+#endif /* KIT_BUILD_TESTS || !HAVE_STRNDUP */
 
 /**
  * kit_strdup_printf:
