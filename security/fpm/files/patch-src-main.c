--- src/main.c.orig	Sat Jun  4 07:32:53 2005
+++ src/main.c	Sat Jun  4 07:33:15 2005
@@ -32,15 +32,16 @@
 int
 main (int argc, char *argv[])
 {
-#ifdef ENABLE_NLS
-  bindtextdomain (PACKAGE, PACKAGE_LOCALE_DIR);
-  textdomain (PACKAGE);
-#endif
   char *opt_file_name = NULL;
   const struct poptOption options[] = {
     {"file", 'f', POPT_ARG_STRING, &opt_file_name, 0,
      N_("Name of the password file to open"), N_("PASSWORDFILE")},
     {NULL, '\0', 0, NULL, 0}};
+
+#ifdef ENABLE_NLS
+  bindtextdomain (PACKAGE, PACKAGE_LOCALE_DIR);
+  textdomain (PACKAGE);
+#endif
 
   gnome_init_with_popt_table("fpm", VERSION, argc, argv, options, 0, NULL);
   // gnome_init("fpm", VERSION, argc, argv);
