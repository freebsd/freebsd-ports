Index: files/patch-redir.c
===================================================================
RCS file: files/patch-redir.c
diff -N files/patch-redir.c
--- /dev/null   1 Jan 1970 00:00:00 -0000
+++ files/patch-redir.c 20 Jun 2004 15:40:43 -0000
@@ -0,0 +1,11 @@
+--- redir.c.orig       Sun Jun 20 18:00:47 2004
++++ redir.c    Sun Jun 20 18:01:25 2004
+@@ -263,7 +263,7 @@
+   int herelen, n, e;
+
+   herestr = expand_string_to_string (redirectee->word, 0);
+-  herelen = strlen (herestr);
++  herelen = (herestr == NULL) ? 0 : strlen (herestr);
+
+   n = write (fd, herestr, herelen);
+   if (n == herelen)


