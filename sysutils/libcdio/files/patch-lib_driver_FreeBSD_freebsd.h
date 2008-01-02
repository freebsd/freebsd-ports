
$FreeBSD$

--- lib/driver/FreeBSD/freebsd.h.orig
+++ lib/driver/FreeBSD/freebsd.h
@@ -158,6 +158,8 @@
 				cdio_drive_write_cap_t *p_write_cap,
 				cdio_drive_misc_cap_t  *p_misc_cap);
 
+int get_media_changed_freebsd (const void *p_user_data);
+
 char *get_mcn_freebsd_ioctl (const _img_private_t *p_env);
 
 void free_freebsd_cam (void *obj);
