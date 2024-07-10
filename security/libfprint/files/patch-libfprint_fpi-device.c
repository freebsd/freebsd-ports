--- libfprint/fpi-device.c.orig        2024-02-20 00:09:54 UTC
+++ libfprint/fpi-device.c
@@ -1539,6 +1539,7 @@ fpi_device_list_complete (FpDevice  *device,
     fpi_device_return_task_in_idle (device, FP_DEVICE_TASK_RETURN_ERROR, error);
 }

+#if !defined(__FreeBSD__)
 static int
 update_attr (const char *attr, const char *value)
 {
@@ -1579,6 +1580,7 @@ update_attr (const char *attr, const char *value)

   return 0;
 }
+#endif

 static void
 complete_suspend_resume_task (FpDevice *device)
@@ -1686,6 +1688,9 @@ fpi_device_configure_wakeup (FpDevice *device, gboolea
 void
 fpi_device_configure_wakeup (FpDevice *device, gboolean enabled)
 {
+#if defined(__FreeBSD__)
+  g_warning ("No device wakeup supported on FreeBSD. NOP");
+#else
   FpDevicePrivate *priv = fp_device_get_instance_private (device);

   switch (priv->type)
@@ -1749,6 +1754,7 @@ fpi_device_configure_wakeup (FpDevice *device, gboolea
                                       fpi_device_error_new (FP_DEVICE_ERROR_GENERAL));
       return;
     }
+#endif
 }

 static void
