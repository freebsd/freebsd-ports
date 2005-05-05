--- redir.c.orig	Tue Mar 12 12:27:38 2002
+++ redir.c	Thu May  5 07:41:18 2005
@@ -263,7 +263,7 @@ write_here_string (fd, redirectee)
   int herelen, n, e;
 
   herestr = expand_string_to_string (redirectee->word, 0);
-  herelen = strlen (herestr);
+  herelen = (herestr == NULL) ? 0 : strlen (herestr);
 
   n = write (fd, herestr, herelen);
   if (n == herelen)
