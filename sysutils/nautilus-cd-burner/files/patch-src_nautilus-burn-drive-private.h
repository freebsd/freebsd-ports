--- src/nautilus-burn-drive-private.h.orig        Sun Nov 19 13:43:24 2006
+++ src/nautilus-burn-drive-private.h        Sun Nov 19 13:43:50 2006
@@ -34,6 +34,7 @@ struct NautilusBurnDrivePrivate {
 
         int                           type;
         char                         *device;
+        char                         *cdrecord_device;
         char                         *display_name;
         int                           max_speed_write;
         int                           max_speed_read;
