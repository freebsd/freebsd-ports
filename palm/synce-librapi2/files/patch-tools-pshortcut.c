--- tools/pshortcut.c.orig	Fri Jan 26 02:19:29 2007
+++ tools/pshortcut.c	Fri Jan 26 02:21:07 2007
@@ -77,6 +77,7 @@
   WCHAR* wide_target = NULL;
   WCHAR *tmp, *tmp_quote;
   int tmpsize;
+  BOOL res;
 
   if (!handle_parameters(argc, argv, &shortcut, &target))
     goto exit;
@@ -123,7 +124,7 @@
   wstr_free_string(tmp_quote);
   wide_target = tmp;
   
-  BOOL res = CeSHCreateShortcut(wide_shortcut, wide_target);
+  res = CeSHCreateShortcut(wide_shortcut, wide_target);
   if (!res)
   {
     fprintf(stderr, "%s: Unable to create shortcut to '%s' at '%s': %s\n",
