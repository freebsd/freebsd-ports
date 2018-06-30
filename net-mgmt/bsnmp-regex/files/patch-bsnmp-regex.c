--- module/bsnmp-regex.c.orig	2011-10-21 16:05:37.000000000 +0700
+++ module/bsnmp-regex.c	2018-06-05 21:16:44.471250000 +0700
@@ -788,7 +788,7 @@ config_var (char *name, char *value, int
     if (strcmp (name, "expire") == 0 || strcmp (name, "expires") == 0) {
 
         i = strtol (value, &t2, 10);
-        if (i <= 0 || *t2)
+        if (i < 0 || *t2)
             emsg ("invalid value for '%s' variable. ignoring: %s", name, value);
         else
             option_expires = i * 100;
