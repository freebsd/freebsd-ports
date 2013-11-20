--- libcheese/cheese-camera-device-monitor.c.orig	2012-08-22 21:04:40.000000000 +0200
+++ libcheese/cheese-camera-device-monitor.c	2013-09-22 23:12:35.072353163 +0200
@@ -33,6 +33,14 @@
   #include <fcntl.h>
   #include <unistd.h>
   #include <sys/ioctl.h>
+  #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+    #include <errno.h>
+    #include <sys/param.h>
+    #include <sys/types.h>
+    #include <sys/socket.h>
+    #include <sys/un.h>
+    #include <linux/videodev.h>
+  #endif
   #if USE_SYS_VIDEOIO_H > 0
     #include <sys/types.h>
     #include <sys/videoio.h>
@@ -302,6 +310,220 @@
   g_list_free (devices);
 }
 
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+static void cheese_camera_device_monitor_init_event (CheeseCameraDeviceMonitor *monitor);
+static gboolean cheese_camera_device_monitor_is_camera (const char *devname);
+ 
+static gboolean cheese_camera_device_monitor_event_inited = FALSE;
+
+static gboolean
+cheese_camera_device_monitor_is_camera (const char *devname){
+  gboolean is_camera = FALSE;
+  int fd;
+  struct v4l2_capability v2cap;
+  g_return_val_if_fail (devname != NULL, FALSE);
+
+  fd = open (devname, O_RDONLY);
+  if (fd < 0)
+  {
+    GST_WARNING("Failed to query: %s", devname);
+    return FALSE;
+  }
+  else{
+     if (ioctl (fd, VIDIOC_QUERYCAP, &v2cap) == 0)
+     {
+       is_camera = ((v2cap.capabilities & 0x00000001)==1);
+     }
+     else{
+       GST_WARNING("Failed to get product name for %s: %s", devname,
+                g_strerror (errno));
+     }
+  }
+
+  close (fd);
+
+  return is_camera;
+}
+
+static char *
+cheese_camera_device_monitor_get_product (const char *devname)
+{
+  int fd;
+  struct v4l2_capability v2cap;
+  char *product = NULL;
+
+  g_return_val_if_fail (devname != NULL, NULL);
+
+  fd = open (devname, O_RDONLY);
+  if (fd < 0)
+  {
+    GST_WARNING("Failed to get product name for %s: %s", devname,
+                g_strerror (errno));
+    return NULL;
+  }
+
+  if (ioctl (fd, VIDIOC_QUERYCAP, &v2cap) == 0)
+  {
+    product = g_strdup ((const char *) v2cap.card);
+  }
+  else
+  {
+    GST_WARNING("Failed to get product name for %s: %s", devname,
+                g_strerror (errno));
+  }
+
+  close (fd);
+
+  return product;
+}
+
+static void
+cheese_camera_device_monitor_process_event (const char *event,
+                                            CheeseCameraDeviceMonitor *monitor)
+{
+  g_return_if_fail (event != NULL);
+
+  GST_INFO ("Received devd event: %s", event);
+
+  switch (event[0])
+  {
+    case '!':
+            {
+              GRegex *rex;
+              GMatchInfo *info;
+
+              rex = g_regex_new ("subsystem=CDEV type=(CREATE|DESTROY) cdev=(video[0-9]+)", 0, 0, NULL);
+              if (g_regex_match (rex, event, 0, &info))
+              {
+                char *devname, *type, *vdev, *product = NULL;
+                CheeseCameraDevice *device;
+                GError *error = NULL;
+
+                type = g_match_info_fetch (info, 1);
+                vdev = g_match_info_fetch (info, 2);
+
+                devname = g_strdup_printf ("/dev/%s", vdev);
+
+                if (g_strcmp0 (type, "DESTROY") == 0)
+                {
+                  g_signal_emit (monitor, monitor_signals[REMOVED], 0,
+                                 devname);
+                }
+                else
+                {
+                  if(cheese_camera_device_monitor_is_camera (devname))
+                  {
+                    product = cheese_camera_device_monitor_get_product (devname);
+                    if (product == NULL)
+                      product = g_strdup ("WebCamd Device");
+                    device = cheese_camera_device_new (devname, devname,
+                                                       product,
+                                                       2,
+                                                       &error);
+                    if (device == NULL)
+                      GST_WARNING ("Device initialization for %s failed: %s",
+                                   devname,
+                                   (error != NULL) ? error->message : "Unknown reason");
+                    g_signal_emit (monitor, monitor_signals[ADDED], 0, device);
+                  }
+
+                  g_free (product);
+                }
+                g_free (devname);
+                g_free (vdev);
+                g_free (type);
+              }
+              g_match_info_free (info);
+              g_regex_unref (rex);
+              break;
+            }
+    default:
+            break;
+  }
+}
+
+static gboolean
+cheese_camera_device_monitor_event_cb (GIOChannel *source,
+                                       GIOCondition condition,
+                                       gpointer user_data)
+{
+  char *event;
+  gsize terminator;
+  GIOStatus status;
+  CheeseCameraDeviceMonitor *monitor;
+
+  monitor = (CheeseCameraDeviceMonitor *) user_data;
+
+  status = g_io_channel_read_line (source, &event, NULL, &terminator, NULL);
+  if (status == G_IO_STATUS_NORMAL)
+  {
+    event[terminator] = 0;
+    cheese_camera_device_monitor_process_event (event, monitor);
+    g_free (event);
+  }
+  else
+  {
+    if (cheese_camera_device_monitor_event_inited)
+    {
+      int fd;
+
+      cheese_camera_device_monitor_init_event (monitor);
+      fd = g_io_channel_unix_get_fd (source);
+      g_io_channel_shutdown (source, FALSE, NULL);
+      close (fd);
+
+      return FALSE;
+    }
+  }
+
+  return TRUE;
+}
+
+void
+cheese_camera_device_monitor_coldplug (CheeseCameraDeviceMonitor *monitor)
+{
+  GDir *dir;
+  GError *error = NULL;
+  const char *fname;
+
+  dir = g_dir_open ("/dev", 0, &error);
+  if (dir == NULL)
+  {
+    GST_WARNING ("Failed to open /dev for reading: %s",
+                 (error != NULL) ? error->message : "Unknown error");
+    return;
+  }
+
+  while ((fname = g_dir_read_name (dir)) != NULL)
+  {
+    if ( strncmp (fname, "video", strlen ("video")) == 0)
+    {
+      char *devname, *product;
+
+      devname = g_strdup_printf ("/dev/%s", fname);
+      if (cheese_camera_device_monitor_is_camera (devname))
+      {
+        CheeseCameraDevice *device;
+        GError *derr = NULL;
+
+        product = cheese_camera_device_monitor_get_product (devname);
+        if (product == NULL)
+          product = g_strdup ("WebCamd Device");
+
+        device = cheese_camera_device_new (devname, devname, product, 2, &derr);
+        if (device == NULL)
+          GST_WARNING ("Device initialization for %s failed: %s", devname,
+                       (derr != NULL) ? derr->message : "Unknown reason");
+
+        g_signal_emit (monitor, monitor_signals[ADDED], 0, device);
+
+        g_free (product);
+      }
+      g_free (devname);
+    }
+  }
+  g_dir_close (dir);
+}
 #else /* HAVE_UDEV */
 void
 cheese_camera_device_monitor_coldplug (CheeseCameraDeviceMonitor *monitor)
@@ -430,6 +652,42 @@
   g_type_class_add_private (klass, sizeof (CheeseCameraDeviceMonitorPrivate));
 }
 
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+static void
+cheese_camera_device_monitor_init_event (CheeseCameraDeviceMonitor *monitor)
+{
+  int event_fd;
+  struct sockaddr_un addr;
+
+  event_fd = socket (PF_UNIX, SOCK_STREAM, 0);
+  if (event_fd < 0)
+  {
+    GST_WARNING ("Failed to create devd socket: %s", g_strerror (errno));
+    cheese_camera_device_monitor_event_inited = FALSE;
+    return;
+  }
+
+  addr.sun_family = AF_UNIX;
+  strncpy (addr.sun_path, "/var/run/devd.pipe", sizeof (addr.sun_path));
+  if (connect (event_fd, (struct sockaddr *) &addr, sizeof (addr)) == 0)
+  {
+    GIOChannel *channel;
+
+    channel = g_io_channel_unix_new (event_fd);
+    g_io_add_watch (channel, G_IO_IN, cheese_camera_device_monitor_event_cb, monitor);
+    g_io_channel_unref (channel);
+    cheese_camera_device_monitor_event_inited = TRUE;
+  }
+  else
+  {
+    GST_WARNING("Failed to connect to /var/run/devd.pipe: %s",
+                g_strerror (errno));
+    close (event_fd);
+    cheese_camera_device_monitor_event_inited = FALSE;
+  }
+}
+#endif
+
 static void
 cheese_camera_device_monitor_init (CheeseCameraDeviceMonitor *monitor)
 {
@@ -440,6 +698,8 @@
   priv->client = g_udev_client_new (subsystems);
   g_signal_connect (G_OBJECT (priv->client), "uevent",
                     G_CALLBACK (cheese_camera_device_monitor_uevent_cb), monitor);
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+  cheese_camera_device_monitor_init_event (monitor);
 #endif /* HAVE_UDEV */
 }
 
