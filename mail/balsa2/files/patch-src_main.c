--- src/main.c.orig	Mon Mar 24 16:48:36 2003
+++ src/main.c	Sun Apr 13 01:00:36 2003
@@ -152,7 +152,7 @@
     gnome_program_init(PACKAGE, VERSION, LIBGNOMEUI_MODULE, argc, argv,
                        GNOME_PARAM_POPT_TABLE, options,
                        GNOME_PARAM_APP_PREFIX, BALSA_STD_PREFIX,
-                       GNOME_PARAM_APP_DATADIR, BALSA_STD_PREFIX "/share",
+                       GNOME_PARAM_APP_DATADIR, BALSA_STD_PREFIX "/share/gnome",
                        NULL);
 }
 
@@ -355,7 +355,7 @@
     /* FIXME: gnome_i18n_get_language seems to have gone away; 
      * is this a reasonable replacement? */
     setlocale(LC_CTYPE,
-              (const char *) gnome_i18n_get_language_list(LC_CTYPE)->data);
+              (const char *) gnome_i18n_get_language_list("LC_CTYPE")->data);
 #endif
 
 #ifdef HAVE_GPGME
