--- ./par.c.orig	2001-04-02 05:25:57.000000000 +0100
+++ ./par.c	2014-02-10 21:14:29.000000000 +0000
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
