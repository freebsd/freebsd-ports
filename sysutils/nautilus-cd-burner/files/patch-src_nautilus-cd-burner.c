--- src/nautilus-cd-burner.c.orig        Fri Jul 14 10:20:19 2006
+++ src/nautilus-cd-burner.c        Sun Nov 19 13:41:34 2006
@@ -27,6 +27,8 @@
 
 #include "config.h"
 
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <time.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -246,7 +248,7 @@ selection_dialog_response (GtkWidget *di
                 /* save selections */
                 gconf_client = gconf_client_get_default ();
                 gconf_client_set_int (gconf_client, "/apps/nautilus-cd-burner/default_speed", speed, NULL);
-                gconf_save_device (gconf_client, nautilus_burn_drive_get_device (drive));
+                gconf_save_device (gconf_client, nautilus_burn_drive_get_cdrecord_device (drive));
                 g_object_unref (gconf_client);
 
                 operation = ncb_operation_new ();
