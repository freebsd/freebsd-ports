--- src/main.c.orig	Thu Jun 20 01:55:36 2002
+++ src/main.c	Thu Jun 20 01:52:11 2002
@@ -336,7 +336,7 @@
     /* FIXME: gnome_i18n_get_language seems to have gone away; 
      * is this a reasonable replacement? */
     setlocale(LC_CTYPE,
-              (const char *) gnome_i18n_get_language_list(LC_CTYPE)->data);
+              (const char *) gnome_i18n_get_language_list("LC_CTYPE")->data);
 #endif
 
 #ifdef BALSA_USE_THREADS
