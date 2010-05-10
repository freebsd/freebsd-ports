--- libcheese/cheese-camera-device-monitor.c.orig	2010-03-29 16:27:42.000000000 -0400
+++ libcheese/cheese-camera-device-monitor.c	2010-04-17 17:57:57.000000000 -0400
@@ -24,24 +24,11 @@
 #endif
 
 #include <glib-object.h>
+#include <glib/gstdio.h>
 #include <dbus/dbus-glib-lowlevel.h>
+#include <libhal.h>
 #include <string.h>
-
-#ifdef HAVE_UDEV
-  #define G_UDEV_API_IS_SUBJECT_TO_CHANGE 1
-  #include <gudev/gudev.h>
-#else
-  #include <fcntl.h>
-  #include <unistd.h>
-  #include <sys/ioctl.h>
-  #if USE_SYS_VIDEOIO_H > 0
-    #include <sys/types.h>
-    #include <sys/videoio.h>
-  #elif defined (__sun)
-    #include <sys/types.h>
-    #include <sys/videodev2.h>
-  #endif /* USE_SYS_VIDEOIO_H */
-#endif
+#include <unistd.h>
 
 #include "cheese-camera-device-monitor.h"
 #include "cheese-marshal.h"
@@ -54,9 +41,9 @@
  * #CheeseCameraDeviceMonitor provides a basic interface for
  * video4linux device enumeration and hotplugging.
  *
- * It uses either GUdev or some platform specific code to list video
+ * It uses either HAL or some platform specific code to list video
  * devices.  It is also capable (right now in linux only, with the
- * udev backend) to monitor device plugging and emit a
+ * hal backend) to monitor device plugging and emit a
  * CheeseCameraDeviceMonitor::added or
  * CheeseCameraDeviceMonitor::removed signal when an event happens.
  */
@@ -80,11 +67,9 @@ enum CheeseCameraDeviceMonitorError
 
 typedef struct
 {
-#ifdef HAVE_UDEV
-  GUdevClient *client;
-#else
+  DBusConnection *connection;
+  LibHalContext *hal_ctx;
   guint filler;
-#endif /* HAVE_UDEV */
 } CheeseCameraDeviceMonitorPrivate;
 
 enum
@@ -102,111 +87,79 @@ cheese_camera_device_monitor_error_quark
   return g_quark_from_static_string ("cheese-camera-error-quark");
 }
 
-#ifdef HAVE_UDEV
 static void
-cheese_camera_device_monitor_added (CheeseCameraDeviceMonitor *monitor,
-                                    GUdevDevice               *udevice)
+cheese_camera_device_monitor_handle_udi (CheeseCameraDeviceMonitor *monitor,
+                                         const char                *udi)
 {
-  const char         *device_file;
-  const char         *product_name;
-  const char         *vendor;
-  const char         *product;
-  const char         *bus;
-  gint                vendor_id   = 0;
-  gint                product_id  = 0;
+  CheeseCameraDeviceMonitorPrivate *priv = CHEESE_CAMERA_DEVICE_MONITOR_GET_PRIVATE (monitor);
+  char               *device_file;
+  char               *product_name;
+  char               *capstr;
   gint                v4l_version = 0;
+  DBusError           error;
 
-  const gchar *devpath = g_udev_device_get_property (udevice, "DEVPATH");
+  GST_INFO ("Checking hal device '%s'", udi);
 
-  GST_INFO ("Checking udev device '%s'", devpath);
+  dbus_error_init (&error);
 
-  bus = g_udev_device_get_property (udevice, "ID_BUS");
-  if (g_strcmp0 (bus, "usb") == 0)
-  {
-    vendor = g_udev_device_get_property (udevice, "ID_VENDOR_ID");
-    if (vendor != NULL)
-      vendor_id = g_ascii_strtoll (vendor, NULL, 16);
-    product = g_udev_device_get_property (udevice, "ID_MODEL_ID");
-    if (product != NULL)
-      product_id = g_ascii_strtoll (vendor, NULL, 16);
-    if (vendor_id == 0 || product_id == 0)
-    {
-      GST_WARNING ("Error getting vendor and product id");
-    }
-    else
-    {
-      GST_INFO ("Found device %04x:%04x, getting capabilities...", vendor_id, product_id);
-    }
-  }
-  else
+  product_name = libhal_device_get_property_string (priv->hal_ctx, udi, "info.product", &error);
+  if (dbus_error_is_set (&error))
   {
-    GST_INFO ("Not an usb device, skipping vendor and model id retrieval");
+    GST_WARNING ("error getting product name: %s: %s", error.name, error.message);
+    dbus_error_free (&error);
+    return;
   }
 
-  device_file = g_udev_device_get_device_file (udevice);
-  if (device_file == NULL)
+  device_file = libhal_device_get_property_string (priv->hal_ctx, udi, "video4linux.device", &error);
+  if (dbus_error_is_set (&error))
   {
-    GST_WARNING ("Error getting V4L device");
+    GST_WARNING ("error getting V4L device for %s: %s: %s", udi, error.name, error.message);
+    dbus_error_free (&error);
+    libhal_free_string (product_name);
     return;
   }
 
-  /* vbi devices support capture capability too, but cannot be used,
-   * so detect them by device name */
-  if (strstr (device_file, "vbi"))
+  if (g_access (device_file, (R_OK | W_OK)) == -1)
   {
-    GST_INFO ("Skipping vbi device: %s", device_file);
+    GST_WARNING ("Device %s does not have proper permissions.  Permissions must be 0666", device_file);
+    libhal_free_string (product_name);
+    libhal_free_string (device_file);
     return;
   }
 
-  v4l_version = g_udev_device_get_property_as_int (udevice, "ID_V4L_VERSION");
-  if (v4l_version == 2 || v4l_version == 1)
+  capstr = libhal_device_get_property_string (priv->hal_ctx, udi, "video4linux.version", &error);
+  if (dbus_error_is_set (&error))
   {
-    const char *caps;
-
-    caps = g_udev_device_get_property (udevice, "ID_V4L_CAPABILITIES");
-    if (caps == NULL || strstr (caps, ":capture:") == NULL)
-    {
-      GST_WARNING ("Device %s seems to not have the capture capability, (radio tuner?)"
-                   "Removing it from device list.", device_file);
-      return;
-    }
-    product_name  = g_udev_device_get_property (udevice, "ID_V4L_PRODUCT");
-  }
-  else if (v4l_version == 0)
-  {
-    GST_ERROR ("Fix your udev installation to include v4l_id, ignoring %s", device_file);
+    GST_WARNING ("error getting V4L version for %s: %s: %s", udi, error.name, error.message);
+    dbus_error_free (&error);
+    libhal_free_string (product_name);
+    libhal_free_string (device_file);
     return;
   }
-  else
-  {
-    g_assert_not_reached ();
-  }
+
+  v4l_version = atoi (capstr);
+  libhal_free_string (capstr);
 
   g_signal_emit (monitor, monitor_signals[ADDED], 0,
-                 devpath,
+                 udi,
                  device_file,
                  product_name,
                  v4l_version);
 }
 
 static void
-cheese_camera_device_monitor_removed (CheeseCameraDeviceMonitor *monitor,
-                                      GUdevDevice               *udevice)
+cheese_camera_device_monitor_removed (LibHalContext             *ctx,
+                                      const char                *udi)
 {
-  g_signal_emit (monitor, monitor_signals[REMOVED], 0,
-                 g_udev_device_get_property (udevice, "DEVPATH"));
-}
+  CheeseCameraDeviceMonitor *monitor;
+  void *data;
 
-static void
-cheese_camera_device_monitor_uevent_cb (GUdevClient               *client,
-                                        const gchar               *action,
-                                        GUdevDevice               *udevice,
-                                        CheeseCameraDeviceMonitor *monitor)
-{
-  if (g_str_equal (action, "remove"))
-    cheese_camera_device_monitor_removed (monitor, udevice);
-  else if (g_str_equal (action, "add"))
-    cheese_camera_device_monitor_added (monitor, udevice);
+  data = libhal_ctx_get_user_data (ctx);
+  g_assert (data);
+
+  monitor = CHEESE_CAMERA_DEVICE_MONITOR (data);
+
+  g_signal_emit (monitor, monitor_signals[REMOVED], 0, udi);
 }
 
 /**
@@ -222,115 +175,85 @@ void
 cheese_camera_device_monitor_coldplug (CheeseCameraDeviceMonitor *monitor)
 {
   CheeseCameraDeviceMonitorPrivate *priv = CHEESE_CAMERA_DEVICE_MONITOR_GET_PRIVATE (monitor);
-  GList                            *devices, *l;
-  gint                              i = 0;
+  int         i;
+  int         num_udis = 0;
+  char      **udis;
+  DBusError   error;
 
-  if (priv->client == NULL)
+  GST_INFO ("Probing devices with HAL...");
+
+  if (priv->hal_ctx == NULL)
     return;
 
-  GST_INFO ("Probing devices with udev...");
+  dbus_error_init (&error);
 
-  devices = g_udev_client_query_by_subsystem (priv->client, "video4linux");
+  udis = libhal_find_device_by_capability (priv->hal_ctx, "video4linux", &num_udis, &error);
 
-  /* Initialize camera structures */
-  for (l = devices; l != NULL; l = l->next)
+  if (dbus_error_is_set (&error))
   {
-    cheese_camera_device_monitor_added (monitor, l->data);
-    g_object_unref (l->data);
-    i++;
+    GST_WARNING ("libhal_find_device_by_capability: %s: %s", error.name, error.message);
+    dbus_error_free (&error);
+    return;
   }
-  g_list_free (devices);
+
+  /* Initialize camera structures */
+  for (i = 0; i < num_udis; i++)
+    cheese_camera_device_monitor_handle_udi (monitor, udis[i]);
+  libhal_free_string_array (udis);
 
   if (i == 0) GST_WARNING ("No device found");
 }
 
-#else /* HAVE_UDEV */
-void
-cheese_camera_device_monitor_coldplug (CheeseCameraDeviceMonitor *monitor)
+static void
+cheese_camera_device_monitor_added (LibHalContext *ctx, const char *udi)
 {
-  #if 0
-  CheeseCameraDeviceMonitorPrivate *priv = CHEESE_CAMERA_DEVICE_MONITOR_GET_PRIVATE (monitor);
-  struct v4l2_capability            v2cap;
-  struct video_capability           v1cap;
-  int                               fd, ok;
-
-  if ((fd = open (device_path, O_RDONLY | O_NONBLOCK)) < 0)
-  {
-    g_warning ("Failed to open %s: %s", device_path, strerror (errno));
-    return;
-  }
-  ok = ioctl (fd, VIDIOC_QUERYCAP, &v2cap);
-  if (ok < 0)
-  {
-    ok = ioctl (fd, VIDIOCGCAP, &v1cap);
-    if (ok < 0)
-    {
-      g_warning ("Error while probing v4l capabilities for %s: %s",
-                 device_path, strerror (errno));
-      close (fd);
-      return;
-    }
-    g_print ("Detected v4l device: %s\n", v1cap.name);
-    g_print ("Device type: %d\n", v1cap.type);
-    gstreamer_src = "v4lsrc";
-    product_name  = v1cap.name;
-  }
-  else
-  {
-    guint cap = v2cap.capabilities;
-    g_print ("Detected v4l2 device: %s\n", v2cap.card);
-    g_print ("Driver: %s, version: %d\n", v2cap.driver, v2cap.version);
-
-    /* g_print ("Bus info: %s\n", v2cap.bus_info); */ /* Doesn't seem anything useful */
-    g_print ("Capabilities: 0x%08X\n", v2cap.capabilities);
-    if (!(cap & V4L2_CAP_VIDEO_CAPTURE))
-    {
-      g_print ("Device %s seems to not have the capture capability, (radio tuner?)\n"
-               "Removing it from device list.\n", device_path);
-      close (fd);
-      return;
-    }
-    gstreamer_src = "v4l2src";
-    product_name  = (char *) v2cap.card;
-  }
-  close (fd);
+  CheeseCameraDeviceMonitor *monitor;
+  char **caps;
+  guint i;
+  void *data;
 
-  GList *devices, *l;
+  data = libhal_ctx_get_user_data (ctx);
+  g_assert (data);
 
-  g_print ("Probing devices with udev...\n");
+  monitor = CHEESE_CAMERA_DEVICE_MONITOR (data);
 
-  if (priv->client == NULL)
+  caps = libhal_device_get_property_strlist (ctx, udi, "info.capabilities", NULL);
+  if (caps == NULL)
     return;
 
-  devices = g_udev_client_query_by_subsystem (priv->client, "video4linux");
-
-  /* Initialize camera structures */
-  for (l = devices; l != NULL; l = l->next)
+  for (i = 0; caps[i] != NULL; i++)
   {
-    cheese_camera_device_monitor_added (monitor, l->data);
-    g_object_unref (l->data);
+    if (g_strcmp0 (caps[i], "video4linux") == 0)
+    {
+      cheese_camera_device_monitor_handle_udi (monitor, udi);
+      break;
+    }
   }
-  g_list_free (devices);
-  #endif
-}
 
-#endif /* HAVE_UDEV */
+  libhal_free_string_array (caps);
+}
 
 static void
 cheese_camera_device_monitor_finalize (GObject *object)
 {
-#ifdef HAVE_UDEV
   CheeseCameraDeviceMonitor *monitor;
 
   monitor = CHEESE_CAMERA_DEVICE_MONITOR (object);
   CheeseCameraDeviceMonitorPrivate *priv = CHEESE_CAMERA_DEVICE_MONITOR_GET_PRIVATE (monitor);
 
-  if (priv->client != NULL)
+  if (priv->connection != NULL)
   {
-    g_object_unref (priv->client);
-    priv->client = NULL;
+    dbus_connection_unref (priv->connection);
+    priv->connection = NULL;
   }
-#endif /* HAVE_UDEV */
+  if (priv->hal_ctx != NULL)
+  {
+    libhal_ctx_set_device_added (priv->hal_ctx, NULL);
+    libhal_ctx_set_device_removed (priv->hal_ctx, NULL);
+    libhal_ctx_free (priv->hal_ctx);
+    priv->hal_ctx = NULL;
+  }
+
   G_OBJECT_CLASS (cheese_camera_device_monitor_parent_class)->finalize (object);
 }
 
@@ -385,14 +308,52 @@ cheese_camera_device_monitor_class_init 
 static void
 cheese_camera_device_monitor_init (CheeseCameraDeviceMonitor *monitor)
 {
-#ifdef HAVE_UDEV
-  CheeseCameraDeviceMonitorPrivate *priv         = CHEESE_CAMERA_DEVICE_MONITOR_GET_PRIVATE (monitor);
-  const gchar *const                subsystems[] = {"video4linux", NULL};
-
-  priv->client = g_udev_client_new (subsystems);
-  g_signal_connect (G_OBJECT (priv->client), "uevent",
-                    G_CALLBACK (cheese_camera_device_monitor_uevent_cb), monitor);
-#endif /* HAVE_UDEV */
+  CheeseCameraDeviceMonitorPrivate *priv = CHEESE_CAMERA_DEVICE_MONITOR_GET_PRIVATE (monitor);
+  LibHalContext *hal_ctx;
+  DBusError      error;
+
+  dbus_error_init (&error);
+
+  priv->connection = dbus_bus_get (DBUS_BUS_SYSTEM, &error);
+  dbus_connection_set_exit_on_disconnect (priv->connection, FALSE);
+
+  hal_ctx = libhal_ctx_new ();
+  if (hal_ctx == NULL)
+  {
+    GST_WARNING ("Could not create libhal context");
+    dbus_error_free (&error);
+    return;
+  }
+
+  if (!libhal_ctx_set_dbus_connection (hal_ctx, priv->connection))
+  {
+    GST_WARNING ("libhal_ctx_set_dbus_connection: %s: %s", error.name, error.message);
+    dbus_error_free (&error);
+    return;
+  }
+
+  if (!libhal_ctx_init (hal_ctx, &error))
+  {
+    if (dbus_error_is_set (&error))
+    {
+      GST_WARNING ("libhal_ctx_init: %s: %s", error.name, error.message);
+      dbus_error_free (&error);
+    }
+    GST_WARNING ("Could not initialise connection to hald.\n"
+	         "Normally this means the HAL daemon (hald) is not running or not ready");
+    return;
+  }
+
+  dbus_connection_setup_with_g_main (priv->connection, NULL);
+
+  if (!libhal_ctx_set_user_data (hal_ctx, monitor))
+    GST_WARNING ("Failed to set user data on HAL context");
+  if (!libhal_ctx_set_device_added (hal_ctx, cheese_camera_device_monitor_added))
+    GST_WARNING ("Failed to connect to device added signal from HAL");
+  if (!libhal_ctx_set_device_removed (hal_ctx, cheese_camera_device_monitor_removed))
+    GST_WARNING ("Failed to connect to device removed signal from HAL");
+
+  priv->hal_ctx = hal_ctx;
 }
 
 /**
