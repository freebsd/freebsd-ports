--- camcontrol.c.orig	2019-09-08 10:38:26 UTC
+++ camcontrol.c
@@ -166,9 +166,11 @@ int cam_is_removable(const char* device_path)
     int timeout = 0, retry_count = 1;
     int unit = 0;
 
-    if (cam_get_device(device_path, name, sizeof name, &unit)
-                == -1)
+    if (cam_get_device(device_path, name, sizeof name, &unit) == -1)
+    {
         errx(1, "%s", cam_errbuf);
+        return (-1);
+    }
 
     if ((cam_dev = cam_open_spec_device(device,unit,O_RDWR,NULL))
                 == NULL)
