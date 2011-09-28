--- main.c.orig	2011-09-28 10:00:33.000000000 +0800
+++ main.c	2011-09-28 10:00:52.000000000 +0800
@@ -2400,7 +2400,7 @@ find_interpreter (char *name)	/* find in
 	  if (try[to - from - 1] != '/')
 	    strcat (try, "/");
 	  strcat (try, name);
-	  if (f = fopen (try, "r"))
+	  if ((f = fopen (try, "r")))
 	    {
 	      fclose (f);
 	      return try;
