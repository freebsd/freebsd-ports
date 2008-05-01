--- src/kit/kit-string.c.orig	2008-04-08 15:44:50.000000000 -0400
+++ src/kit/kit-string.c	2008-04-22 01:00:49.000000000 -0400
@@ -113,6 +113,28 @@ out:
 
 #else
 
+#ifndef HAVE_STRNDUP
+static char
+*strndup ( const char *s, size_t n)
+{
+        size_t nAvail;
+        char *p;
+
+        if ( !s )
+                return NULL;
+
+        if ( strlen(s) > n )
+                nAvail = n + 1;
+        else
+                nAvail = strlen(s) + 1;
+        p = malloc ( nAvail );
+        memcpy ( p, s, nAvail );
+        p[nAvail - 1] = '\0';
+
+        return p;
+}
+#endif
+
 char *
 kit_strdup (const char *s)
 {
