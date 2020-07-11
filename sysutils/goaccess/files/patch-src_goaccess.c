--- src/goaccess.c.orig	2020-05-17 12:34:51 UTC
+++ src/goaccess.c
@@ -1175,8 +1175,10 @@ set_locale (void) {
   char *loc_ctype;
 
   setlocale (LC_ALL, "");
+#ifdef ENABLE_NLS
   bindtextdomain (PACKAGE, LOCALEDIR);
   textdomain (PACKAGE);
+#endif
 
   loc_ctype = getenv ("LC_CTYPE");
   if (loc_ctype != NULL)
