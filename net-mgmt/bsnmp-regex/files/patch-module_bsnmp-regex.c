--- module/bsnmp-regex.c.orig	2011-10-21 09:05:37 UTC
+++ module/bsnmp-regex.c
@@ -788,7 +788,7 @@ config_var (char *name, char *value, int line)
     if (strcmp (name, "expire") == 0 || strcmp (name, "expires") == 0) {
 
         i = strtol (value, &t2, 10);
-        if (i <= 0 || *t2)
+        if (i < 0 || *t2)
             emsg ("invalid value for '%s' variable. ignoring: %s", name, value);
         else
             option_expires = i * 100;
