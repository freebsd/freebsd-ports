
$FreeBSD$

--- lib/driver/FreeBSD/freebsd.c.orig
+++ lib/driver/FreeBSD/freebsd.c
@@ -743,6 +743,27 @@
 #endif /*HAVE_FREEBSD_CDROM*/
 }
 
+/*! Find out if media has changed since the last call.  @param
+  p_user_data the environment of the CD object to be acted upon.
+  @return 1 if media has changed since last call, 0 if not. Error
+  return codes are the same as driver_return_code_t
+   */
+int
+get_media_changed_freebsd (const void *p_user_data)
+{
+#ifdef HAVE_FREEBSD_CDROM
+  const _img_private_t *p_env = p_user_data;
+  if ( p_env->access_mode == _AM_CAM ) {
+    return mmc_get_media_changed( p_env->gen.cdio );
+  }
+  else
+    return DRIVER_OP_UNSUPPORTED;
+#else 
+  return DRIVER_OP_NO_DRIVER;
+#endif /*HAVE_FREEBSD_CDROM*/
+}
+
+
 /*!
   Initialization routine. This is the only thing that doesn't
   get called via a function pointer. In fact *we* are the
@@ -790,6 +811,7 @@
     .get_discmode           = get_discmode_generic,
     .get_drive_cap          = get_drive_cap_freebsd,
     .get_first_track_num    = get_first_track_num_generic,
+    .get_media_changed      = get_media_changed_freebsd,
     .get_mcn                = get_mcn_freebsd,
     .get_num_tracks         = get_num_tracks_generic,
     .get_track_channels     = get_track_channels_generic,
