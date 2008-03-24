--- src/nautilus-burn-recorder.c.orig        Fri Sep 29 14:18:37 2006
+++ src/nautilus-burn-recorder.c        Mon Nov 20 18:13:24 2006
@@ -1343,7 +1343,7 @@ nautilus_burn_recorder_write_cdrecord (N
                 g_ptr_array_add (argv, "cdrdao");
                 g_ptr_array_add (argv, "write");
                 g_ptr_array_add (argv, "--device");
-                g_ptr_array_add (argv, (char *)nautilus_burn_drive_get_device (drive));
+                g_ptr_array_add (argv, (char *)nautilus_burn_drive_get_cdrecord_device (drive));
                 g_ptr_array_add (argv, "--speed");
                 speed_str = g_strdup_printf ("%d", speed);
                 g_ptr_array_add (argv, speed_str);
@@ -1375,7 +1375,7 @@ nautilus_burn_recorder_write_cdrecord (N
                 if (speed != 0) {
                         g_ptr_array_add (argv, speed_str);
                 }
-                dev_str = g_strdup_printf ("dev=%s", nautilus_burn_drive_get_device (drive));
+                dev_str = g_strdup_printf ("dev=%s", nautilus_burn_drive_get_cdrecord_device (drive));
                 g_ptr_array_add (argv, dev_str);
                 if (flags & NAUTILUS_BURN_RECORDER_WRITE_DUMMY_WRITE) {
                         g_ptr_array_add (argv, "-dummy");
@@ -1486,7 +1486,7 @@ nautilus_burn_recorder_blank_disc_cdreco
         argv = g_ptr_array_new ();
         g_ptr_array_add (argv, "cdrecord");
 
-        dev_str = g_strdup_printf ("dev=%s", nautilus_burn_drive_get_device (drive));
+        dev_str = g_strdup_printf ("dev=%s", nautilus_burn_drive_get_cdrecord_device (drive));
         g_ptr_array_add (argv, dev_str);
         g_ptr_array_add (argv, "-v");
 
