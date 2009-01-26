--- hald/freebsd/hf-devtree.c.orig	2008-05-07 19:24:03.000000000 -0400
+++ hald/freebsd/hf-devtree.c	2009-01-25 17:17:02.000000000 -0500
@@ -426,7 +426,13 @@ hf_devtree_probe (void)
 	  HalDevice *device;
 
 	  device = hf_devtree_device_new(parent, info->handler, info->unit);
-	  hf_device_preprobe_and_add(device);
+	  if (hf_device_preprobe(device))
+            {
+              if (hal_device_has_capability(device, "input.mouse"))
+                hf_runner_run_sync(device, 0, "hald-probe-mouse", NULL);
+
+	      hf_device_add(device);
+	    }
 	}
 
       devices = g_slist_delete_link(devices, root);
@@ -434,6 +440,17 @@ hf_devtree_probe (void)
     }
 }
 
+static gboolean
+hf_devtree_rescan (HalDevice *device)
+{
+  if (hal_device_has_capability(device, "input.mouse"))
+    {
+      hf_runner_run_sync(device, 0, "hald-probe-mouse", NULL);
+      return TRUE;
+    }
+  return FALSE;
+}
+
 HalDevice *
 hf_devtree_find_from_name (HalDeviceStore *store, const char *name)
 {
@@ -597,5 +614,6 @@ hf_devtree_is_driver (const char *name, 
 }
 
 HFHandler hf_devtree_handler = {
-  .probe = hf_devtree_probe
+  .probe = hf_devtree_probe,
+  .device_rescan = hf_devtree_rescan
 };
