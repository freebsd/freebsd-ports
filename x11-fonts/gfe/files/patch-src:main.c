diff -ruN src.dist/main.c src/main.c
--- src.dist/main.c    Tue Feb 26 09:11:19 2002
+++ src/main.c Tue Feb 26 09:11:47 2002
@@ -37,6 +37,7 @@
   int i;
 
   /* process gtk/X switches */
+  gtk_set_locale();
   gtk_init(&argc, &argv);
 
   show_version = FALSE;
