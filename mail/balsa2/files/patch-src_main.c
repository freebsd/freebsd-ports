--- src/main.c.orig	Sun Jan 18 06:39:47 2004
+++ src/main.c	Sun Jan 18 21:38:15 2004
@@ -233,7 +233,7 @@
     gnome_program_init(PACKAGE, VERSION, LIBGNOMEUI_MODULE, argc, argv,
                        GNOME_PARAM_POPT_TABLE, options,
                        GNOME_PARAM_APP_PREFIX, BALSA_STD_PREFIX,
-                       GNOME_PARAM_APP_DATADIR, BALSA_STD_PREFIX "/share",
+                       GNOME_PARAM_APP_DATADIR, BALSA_STD_PREFIX "/share/gnome",
 		       GNOME_PARAM_HUMAN_READABLE_NAME, _("The Balsa E-Mail Client"),
                        NULL);
 
