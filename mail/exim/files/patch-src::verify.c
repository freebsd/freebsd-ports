#
# Fix SEGV on long headers when verify = header_syntax is used
#  <http://www.guninski.com/exim1.html>
#
--- src/verify.c.orig	Thu May  6 15:46:44 2004
+++ src/verify.c	Thu May  6 15:47:27 2004
@@ -1264,14 +1264,9 @@
 
     if (recipient == NULL && Ustrcmp(errmess, "empty address") != 0)
       {
-      uschar hname[64];
-      uschar *t = h->text;
-      uschar *tt = hname;
+      uschar *t;
       uschar *verb = US"is";
       int len;
-
-      while (*t != ':') *tt++ = *t++;
-      *tt = 0;
 
       /* Arrange not to include any white space at the end in the
       error message. */
