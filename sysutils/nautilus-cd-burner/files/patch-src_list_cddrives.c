--- src/list_cddrives.c.orig	Sun Nov 19 13:36:40 2006
+++ src/list_cddrives.c	Sun Nov 19 13:37:08 2006
@@ -49,6 +49,7 @@ list_drive_info (NautilusBurnDrive *driv
 	g_print ("Drive:\n");
 	g_print ("  name:\t\t\t%s\n", display_name);
 	g_print ("  device:\t\t%s\n", nautilus_burn_drive_get_device (drive));
+	g_print ("  cdrecord device:\t%s\n", nautilus_burn_drive_get_cdrecord_device (drive));
 	g_print ("  door:\t\t\t%s\n", door_is_open ? "open" : "closed");
 	g_print ("  type:\t\t\t%s\n", type_str);
 	g_print ("  is mounted:\t\t%s\n", is_mounted ? "TRUE" : "FALSE");
