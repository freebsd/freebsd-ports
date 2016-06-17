--- src/main.c.orig	2000-06-29 08:16:34 UTC
+++ src/main.c
@@ -37,6 +37,7 @@ main(int argc, char *argv[])
   int i;
 
   /* process gtk/X switches */
+  gtk_set_locale();
   gtk_init(&argc, &argv);
 
   show_version = FALSE;
