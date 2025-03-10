--- src/xfpm-backlight-helper.c.orig	2024-11-21 06:26:21 UTC
+++ src/xfpm-backlight-helper.c
@@ -51,6 +51,8 @@
 #define EXIT_CODE_INVALID_USER 4
 #define EXIT_CODE_NO_BRIGHTNESS_SWITCH 5
 
+#define MAX_DEVICE_NUM 8
+
 #ifndef BACKEND_TYPE_FREEBSD
 #define BACKLIGHT_SYSFS_LOCATION "/sys/class/backlight"
 #define BRIGHTNESS_SWITCH_LOCATION "/sys/module/video/parameters/brightness_switch_enabled"
@@ -211,20 +213,24 @@ backlight_helper_get_device (void)
   /* devices in priority order */
   gchar *types[] = { "lcd", "crt", "out", "ext", "tv", NULL };
   gchar *device = NULL;
-  gint i;
+  gint i, j;
 
-  device = (gchar *) g_malloc (sizeof (gchar));
+  device = (gchar *) g_malloc (sizeof (gchar) * 8);
 
   for (i = 0; types[i] != NULL; i++)
   {
-    g_snprintf (device, (gulong) strlen (types[i]), "%s0", types[i]);
+    for (j = 0; j < MAX_DEVICE_NUM; j++) {
+      g_snprintf (device, 8, "%s%i", types[i], j);
 
-    /* stop, when first device is found */
-    if (acpi_video_is_enabled (device))
-      break;
+      /* stop, when first device is found */
+      if (acpi_video_is_enabled (device))
+        return (device);
+    }
   }
 
-  return device;
+  g_free (device);
+
+  return (NULL);
 }
 
 /*
