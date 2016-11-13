--- panel-plugin/devices.c.orig	2014-04-26 21:31:42 UTC
+++ panel-plugin/devices.c
@@ -329,9 +329,11 @@ disk_umount (t_disk *pdisk, char* umount
     {
 
         DBG("disk_umount: dev=%s, mountpoint=%s, umount_command=%s, show_message_dialog=%d, eject=%d, type=%s", pdisk->device, pdisk->mount_point, umount_command, show_message_dialog, eject, pdisk->mount_info->type);
+#if !defined(__FreeBSD__) || !defined(__DragonFly__)
         if (strstr(pdisk->mount_info->type, "fuse"))
           deviceprintf(&tmp, "fusermount -u %m", pdisk->device);
         else
+#endif
           deviceprintf(&tmp, umount_command, pdisk->device);
         
         mountpointprintf(&cmd, tmp, pdisk->mount_point);
