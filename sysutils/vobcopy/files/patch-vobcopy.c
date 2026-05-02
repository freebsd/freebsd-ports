--- vobcopy.c.orig	2026-04-19 12:31:47 UTC
+++ vobcopy.c
@@ -160,7 +160,7 @@ and potentially fatal."  - Thanks Leigh!*/
 #if defined( __gettext__ )
   setlocale(LC_ALL, "");
   textdomain("vobcopy");
-  bindtextdomain("vobcopy", "/usr/share/locale");
+  bindtextdomain("vobcopy", "/usr/local/share/locale");
 #endif
 
   /* initialize string */
