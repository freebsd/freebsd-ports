--- par.c.orig	Sun Mar 28 16:00:15 2004
+++ par.c	Sun Mar 28 16:04:00 2004
@@ -403,7 +403,8 @@
         }
         continue;
       }
-      if (isspace(c)) ch = ' ';
+      // Exclude non-breaking space from the class of space chars
+      if (isspace(c) && isascii(c)) ch = ' ';
       else blank = 0;
       additem(cbuf, &ch, errmsg);
       if (*errmsg) goto rlcleanup;
