--- src/make-iso.c.orig        Sun Nov 19 13:34:29 2006
+++ src/make-iso.c        Sun Nov 19 13:36:03 2006
@@ -1367,7 +1367,7 @@ get_disc_info (NautilusBurnIso   *iso,
                                                               &has_data,
                                                               &_has_audio);
         if (_has_audio) {
-                device_arg = g_strdup_printf ("%s", nautilus_burn_drive_get_device (drive));
+                device_arg = g_strdup_printf ("%s", nautilus_burn_drive_get_cdrecord_device (drive));
 
                 argv = g_ptr_array_new ();
                 g_ptr_array_add (argv, "cdrdao");
@@ -1377,7 +1377,7 @@ get_disc_info (NautilusBurnIso   *iso,
                 g_ptr_array_add (argv, NULL);
 
         } else {
-                device_arg = g_strdup_printf ("-dev=%s", nautilus_burn_drive_get_device (drive));
+                device_arg = g_strdup_printf ("-dev=%s", nautilus_burn_drive_get_cdrecord_device (drive));
 
                 argv = g_ptr_array_new ();
                 g_ptr_array_add (argv, "readcd");
@@ -1547,7 +1547,7 @@ nautilus_burn_iso_make_from_drive (Nauti
                 g_ptr_array_add (argv, "--datafile");
                 g_ptr_array_add (argv, (char *)filename);
                 g_ptr_array_add (argv, "--device");
-                g_ptr_array_add (argv, (char *)nautilus_burn_drive_get_device (drive));
+                g_ptr_array_add (argv, (char *)nautilus_burn_drive_get_cdrecord_device (drive));
                 g_ptr_array_add (argv, "-v");
                 g_ptr_array_add (argv, "2");
                 g_ptr_array_add (argv, (char *)toc_filename_arg);
@@ -1559,7 +1559,7 @@ nautilus_burn_iso_make_from_drive (Nauti
 
                 filename_arg = g_strdup_printf ("f=%s", filename);
 
-                dev_arg = g_strdup_printf ("dev=%s", nautilus_burn_drive_get_device (drive));
+                dev_arg = g_strdup_printf ("dev=%s", nautilus_burn_drive_get_cdrecord_device (drive));
 
                 argv = g_ptr_array_new ();
                 g_ptr_array_add (argv, "readcd");
