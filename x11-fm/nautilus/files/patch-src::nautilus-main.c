
$FreeBSD$

--- src/nautilus-main.c	2002/02/26 22:34:03	1.1
+++ src/nautilus-main.c	2002/02/26 22:43:21
@@ -140,6 +140,7 @@
 	CORBA_ORB orb;
 	NautilusApplication *application;
 	char **argv_copy;
+	char *ld_library_path;
 
 	struct poptOption options[] = {
 #ifndef NAUTILUS_OMIT_SELF_CHECK
@@ -205,6 +206,13 @@
 				    argc, argv, options, 0,
 				    &popt_context);
 	eel_setenv ("DISPLAY", DisplayString (GDK_DISPLAY ()), TRUE);
+	ld_library_path = g_getenv ("LD_LIBRARY_PATH");
+	if (ld_library_path == NULL)
+		ld_library_path = "";
+	else
+		ld_library_path = g_strconcat (ld_library_path, ":", NULL);
+	ld_library_path = g_strconcat(ld_library_path, MOZILLA_LIB_PLACE, NULL);
+	eel_setenv ("LD_LIBRARY_PATH", ld_library_path, TRUE);
 	orb = oaf_init (argc, argv);
         gdk_rgb_init ();
 
