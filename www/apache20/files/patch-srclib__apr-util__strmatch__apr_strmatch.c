--- ./srclib/apr-util/strmatch/apr_strmatch.c.orig	2005-02-04 15:39:09.000000000 -0500
+++ ./srclib/apr-util/strmatch/apr_strmatch.c	2010-05-06 16:06:03.717832055 -0400
@@ -103,13 +103,13 @@
     if (case_sensitive) {
         pattern->compare = match_boyer_moore_horspool;
         for (i = 0; i < pattern->length - 1; i++) {
-            shift[(int)s[i]] = pattern->length - i - 1;
+            shift[(unsigned char)s[i]] = pattern->length - i - 1;
         }
     }
     else {
         pattern->compare = match_boyer_moore_horspool_nocase;
         for (i = 0; i < pattern->length - 1; i++) {
-            shift[apr_tolower(s[i])] = pattern->length - i - 1;
+            shift[(unsigned char)apr_tolower(s[i])] = pattern->length - i - 1;
         }
     }
     pattern->context = shift;
