--- libfprint/fp-device.c.orig	2024-09-06 12:19:55.705243000 +0200
+++ libfprint/fp-device.c	2024-09-06 12:22:36.396895000 +0200
@@ -362,12 +362,14 @@
 static void
 device_idle_probe_cb (FpDevice *self, gpointer user_data)
 {
+#if defined(__linux)
   /* This should not be an idle handler, see comment where it is registered.
    *
    * This effectively disables USB "persist" for us, and possibly turns off
    * USB wakeup if it was enabled for some reason.
    */
   fpi_device_configure_wakeup (self, FALSE);
+#endif
 
   if (!FP_DEVICE_GET_CLASS (self)->probe)
     fpi_device_probe_complete (self, NULL, NULL, NULL);
