--- libfprint/fpi-device.c.orig	2024-09-05 16:24:40.482243000 +0200
+++ libfprint/fpi-device.c	2024-09-06 12:13:49.123856000 +0200
@@ -1690,6 +1690,7 @@
     }
 }
 
+#if defined(__linux)
 void
 fpi_device_configure_wakeup (FpDevice *device, gboolean enabled)
 {
@@ -1757,6 +1758,7 @@
       return;
     }
 }
+#endif
 
 static void
 fpi_device_suspend_completed (FpDevice *device)
@@ -1764,9 +1766,11 @@
   g_autoptr(GTask) task = NULL;
   FpDevicePrivate *priv = fp_device_get_instance_private (device);
 
+#if defined(__linux)
   /* We have an ongoing operation, allow the device to wake up the machine. */
   if (priv->current_action != FPI_DEVICE_ACTION_NONE)
     fpi_device_configure_wakeup (device, TRUE);
+#endif
 
   if (priv->critical_section)
     g_warning ("Driver was in a critical section at suspend time. It likely deadlocked!");
@@ -1848,7 +1852,9 @@
   g_return_if_fail (priv->suspend_resume_task);
 
   priv->is_suspended = FALSE;
+#if defined(__linux)
   fpi_device_configure_wakeup (device, FALSE);
+#endif
 
   task = g_steal_pointer (&priv->suspend_resume_task);
 
