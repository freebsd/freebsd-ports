--- src/goaccess.c.orig	2018-12-16 01:14:48 UTC
+++ src/goaccess.c
@@ -1202,8 +1202,10 @@ set_locale (void)
   char *loc_ctype;
 
   setlocale (LC_ALL, "");
+#ifdef ENABLE_NLS
   bindtextdomain (PACKAGE, LOCALEDIR);
   textdomain (PACKAGE);
+#endif
 
   loc_ctype = getenv ("LC_CTYPE");
   if (loc_ctype != NULL)
