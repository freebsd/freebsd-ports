--- ./reformat.c.orig	2014-02-10 21:14:43.000000000 +0000
+++ ./reformat.c	2014-02-10 21:17:35.000000000 +0000
@@ -335,7 +335,7 @@
     for (end = *line;  *end;  ++end);
     if (end - *line < affix) {
       sprintf(errmsg,
-              "Line %d shorter than <prefix> + <suffix> = %d + %d = %d\n",
+              "Line %zd shorter than <prefix> + <suffix> = %d + %d = %d\n",
               line - inlines + 1, prefix, suffix, affix);
       goto rfcleanup;
     }
