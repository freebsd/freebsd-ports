--- imap/browse.c.orig	Thu Aug 11 13:13:13 2005
+++ imap/browse.c	Sat Jul  1 16:30:28 2006
@@ -481,7 +481,7 @@
 
             if (*s == '\"') {
               s++;
-              while (*s && *s != '\"') {
+              while (*s && *s != '\"' && n < sizeof (ns) - 1) {
                 if (*s == '\\')
                   s++;
                 ns[n++] = *s;
@@ -491,11 +491,13 @@
                 s++;
             }
             else
-              while (*s && !ISSPACE (*s)) {
+              while (*s && !ISSPACE (*s) && n < sizeof (ns) - 1) {
                 ns[n++] = *s;
                 s++;
               }
             ns[n] = '\0';
+	    if (n == sizeof (ns) - 1)
+	      debug_print (1, ("browse_get_namespace: too long: [%s]\n", ns));
             /* delim? */
             s = imap_next_word (s);
             /* delimiter is meaningless if namespace is "". Why does
