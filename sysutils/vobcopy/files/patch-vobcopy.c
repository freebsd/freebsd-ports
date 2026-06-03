--- vobcopy.c.orig	2026-05-18 12:42:51 UTC
+++ vobcopy.c
@@ -185,7 +185,7 @@ and potentially fatal."  - Thanks Leigh!*/
 #if defined( __gettext__ )
   setlocale(LC_ALL, "");
   textdomain("vobcopy");
-  bindtextdomain("vobcopy", "/usr/share/locale");
+  bindtextdomain("vobcopy", "/usr/local/share/locale");
 #endif
 
   /* initialize string */
