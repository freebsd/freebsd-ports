--- tools/hal-storage-eject.c.orig	2008-10-27 13:23:11.000000000 -0400
+++ tools/hal-storage-eject.c	2008-10-27 13:23:23.000000000 -0400
@@ -190,7 +190,7 @@ main (int argc, char *argv[])
 				unknown_eject_error ("Cannot obtain lock on /media/.hal-mtab");
 			}
 			handle_unmount (hal_ctx, 
-					udi, volume_to_unmount, drive, 
+					volume_udi, volume_to_unmount, drive, 
 					libhal_volume_get_device_file (volume_to_unmount), 
 					invoked_by_uid, invoked_by_syscon_name,
 					FALSE, FALSE); /* use neither lazy nor force */
