--- src/kit/kit-string.c.orig	2008-04-08 15:44:50.000000000 -0400
+++ src/kit/kit-string.c	2008-07-03 18:17:57.000000000 -0400
@@ -113,6 +113,33 @@ out:
 
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
+	if (memchr(s, '\0', n) != NULL) {
+		nAvail = strlen(s);
+        	if ( nAvail > n )
+                	nAvail = n;
+	} else {
+		nAvail = n;
+	}
+        p = malloc ( nAvail + 1 );
+	if ( p == NULL)
+		return NULL;
+        memcpy ( p, s, nAvail );
+        p[nAvail] = '\0';
+
+        return p;
+}
+#endif
+
 char *
 kit_strdup (const char *s)
 {
