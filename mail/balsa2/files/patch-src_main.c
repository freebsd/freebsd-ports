--- src/main.c.orig	Mon Sep 15 06:45:59 2003
+++ src/main.c	Thu Oct  2 01:50:21 2003
@@ -150,7 +150,7 @@
     gnome_program_init(PACKAGE, VERSION, LIBGNOMEUI_MODULE, argc, argv,
                        GNOME_PARAM_POPT_TABLE, options,
                        GNOME_PARAM_APP_PREFIX, BALSA_STD_PREFIX,
-                       GNOME_PARAM_APP_DATADIR, BALSA_STD_PREFIX "/share",
+                       GNOME_PARAM_APP_DATADIR, BALSA_STD_PREFIX "/share/gnome",
                        NULL);
 }
 
