--- libfprint/drivers/goodixmoc/goodix.c.orig  2024-02-20 00:09:54 UTC
+++ libfprint/drivers/goodixmoc/goodix.c
@@ -1328,8 +1328,11 @@ gx_fp_probe (FpDevice *device)
       return;
     }

+#ifndef __FreeBSD__
   if (!g_usb_device_reset (usb_dev, &error))
     goto err_close;
+#endif

   if (!g_usb_device_claim_interface (usb_dev, 0, 0, &error))
     goto err_close;
@@ -1421,11 +1424,13 @@ gx_fp_init (FpDevice *device)
     }
   self->sensorcfg->config[6] = self->max_enroll_stage;

+#ifndef __FreeBSD__
   if (!g_usb_device_reset (fpi_device_get_usb_device (device), &error))
     {
       fpi_device_open_complete (FP_DEVICE (self), error);
       return;
     }
+#endif

   /* Claim usb interface */
   if (!g_usb_device_claim_interface (fpi_device_get_usb_device (device), 0, 0, &error))
