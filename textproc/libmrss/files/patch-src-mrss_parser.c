--- src/mrss_parser.c.orig	Mon Apr  2 20:55:34 2007
+++ src/mrss_parser.c	Thu Apr 26 10:57:53 2007
@@ -151,12 +151,9 @@
       char datebuf[256];
       stm.tm_year -= 1900;
 
-      if (!data->c_locale
-	  && !(data->c_locale = newlocale (LC_ALL_MASK, "C", NULL)))
-	return NULL;
-
-      strftime_l (datebuf, sizeof (datebuf), "%a, %d %b %Y %H:%M:%S %z", &stm,
-		  data->c_locale);
+      free (datestr);
+      strftime (datebuf, sizeof (datebuf), "%a, %d %b %Y %H:%M:%S %z",
+                &stm);
 
       return strdup (datebuf);
     }
