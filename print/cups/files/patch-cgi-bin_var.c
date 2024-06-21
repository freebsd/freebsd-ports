--- cgi-bin/var.c.orig	2024-06-18 11:11:05 UTC
+++ cgi-bin/var.c
@@ -191,7 +191,7 @@ cgiGetCheckbox(const char *name)	/* I - Name of form f
   int		ret;			/* Return value */
 
 
-  ret = value && !_cups_strcasecmp(value, "checkbox");
+  ret = value && !_cups_strcasecmp(value, "on");
 
   if (!ret && value)
   {
