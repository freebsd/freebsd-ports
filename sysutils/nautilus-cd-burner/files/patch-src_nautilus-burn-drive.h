--- src/nautilus-burn-drive.h.orig        Sun Nov 19 13:37:32 2006
+++ src/nautilus-burn-drive.h        Sun Nov 19 13:37:55 2006
@@ -127,6 +127,7 @@ gboolean              nautilus_burn_driv
 int                   nautilus_burn_drive_get_drive_type           (NautilusBurnDrive       *drive);
 char *                nautilus_burn_drive_get_name_for_display     (NautilusBurnDrive       *drive);
 const char *          nautilus_burn_drive_get_device               (NautilusBurnDrive       *drive);
+const char *          nautilus_burn_drive_get_cdrecord_device               (NautilusBurnDrive       *drive);
 
 /* Capabilities */
 gboolean              nautilus_burn_drive_can_write                (NautilusBurnDrive       *drive);
