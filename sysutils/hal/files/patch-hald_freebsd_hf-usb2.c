--- hald/freebsd/hf-usb2.c.orig	2009-08-24 07:42:29.000000000 -0500
+++ hald/freebsd/hf-usb2.c	2010-03-17 22:25:17.000000000 -0500
@@ -42,22 +42,6 @@
 static struct libusb20_backend *hf_usb2_be = NULL;
 
 static void
-hf_usb2_copy_parent (HalDevice *parent,
-		     const char *key,
-		     gpointer user_data)
-{
-  HalDevice *device;
-
-  g_return_if_fail(HAL_IS_DEVICE(parent));
-  g_return_if_fail(HAL_IS_DEVICE(user_data));
-
-  device = HAL_DEVICE(user_data);
-
-  if (! strncmp(key, "usb_device.", strlen("usb_device.")))
-    hal_device_copy_property(parent, key, device, key);
-}
-
-static void
 hf_usb2_probe_interfaces(HalDevice *parent)
 {
   int num_interfaces;
@@ -79,9 +63,9 @@
 
       hal_device_property_set_string(device, "info.subsystem", "usb");
       hal_device_property_set_int(device, "usb.interface.number", i);
-      hal_device_property_foreach(parent, hf_usb2_copy_parent, device);
       hal_device_copy_property(parent, "info.product", device, "info.product");
       hal_device_copy_property(parent, "info.vendor", device, "info.vendor");
+      hal_device_merge_with_rewrite(device, parent, "usb.", "usb_device.");
 
       if (hf_device_preprobe(device))
         {
@@ -98,10 +82,10 @@
 	  if (driver)
             {
 	      if (! strcmp(driver, "ukbd"))
-                hf_device_set_input(device, "keyboard", NULL);
-	      else if (! strcmp(driver, "ums"))
+                hf_device_set_input(device, "keyboard", "keys", NULL);
+	      else if (! strcmp(driver, "ums") || ! strcmp(driver, "atp"))
                 {
-                  hf_device_set_input(device, "mouse", devname);
+                  hf_device_set_input(device, "mouse", NULL, devname);
 	          hf_runner_run_sync(device, 0, "hald-probe-mouse", NULL);
 	        }
 	      else if (! strcmp(driver, "uhid"))
@@ -133,6 +117,11 @@
                   hf_usb_add_webcam_properties(device);
 	        }
 	    }
+	  else
+            {
+	      /* Try and detect webcamd devices. */
+              hf_runner_run_sync(device, 0, "hald-probe-video4linux", NULL);
+	    }
 
 	  hf_usb_device_compute_udi(device);
 	  hf_device_add(device);
@@ -192,11 +181,12 @@
       addr = libusb20_dev_get_address(pdev);
 
       if (addr == 1)
-        parent = hf_devtree_find_parent_from_info(hald_get_gdl(), "usbus", bus);
+        parent = hf_devtree_find_from_info(hald_get_gdl(), "usbus", bus);
       else
         parent = hf_device_store_match(hald_get_gdl(), "usb_device.bus_number",
           HAL_PROPERTY_TYPE_INT32, bus, "usb_device.port_number",
-	  HAL_PROPERTY_TYPE_INT32, addr - 1, NULL);
+	  HAL_PROPERTY_TYPE_INT32, addr - 1, "info.bus",
+	  HAL_PROPERTY_TYPE_STRING, "usb_device", NULL);
       if (! parent || hal_device_property_get_bool(parent, "info.ignore"))
         continue;
 
@@ -216,7 +206,13 @@
   HalDevice *parent_device;
   int bus, addr, pbus, paddr;
 
-  if (strncmp(name, "ugen", strlen("ugen")))
+  if (! parent)
+    return FALSE;
+
+  if (strncmp(name, "ugen", strlen("ugen")) &&
+      ! strncmp(parent, "uhub", strlen("uhub")))
+    return TRUE;
+  else if (strncmp(name, "ugen", strlen("ugen")))
     return FALSE;
   else if (strncmp(parent, "ugen", strlen("ugen")))
     return TRUE;
@@ -232,7 +228,8 @@
 
   parent_device = hf_device_store_match(hald_get_gdl(),
     "usb_device.bus_number", HAL_PROPERTY_TYPE_INT32, pbus,
-    "usb_device.port_number", HAL_PROPERTY_TYPE_INT32, paddr, NULL);
+    "usb_device.port_number", HAL_PROPERTY_TYPE_INT32, paddr, "info.bus",
+    HAL_PROPERTY_TYPE_STRING, "usb_device", NULL);
 
   if (parent_device && ! hal_device_property_get_bool(parent_device,
       "info.ignore"))
@@ -255,8 +252,6 @@
 
   if (strncmp(name, "ugen", strlen("ugen")))
     return FALSE;
-  else if (strncmp(parent, "ugen", strlen("ugen")))
-    return TRUE;
 
   if (sscanf(name, "ugen%i.%i", &bus, &addr) != 2)
     return FALSE;
@@ -265,7 +260,8 @@
 
   device = hf_device_store_match(hald_get_gdl(), "usb_device.bus_number",
     HAL_PROPERTY_TYPE_INT32, bus, "usb_device.port_number",
-    HAL_PROPERTY_TYPE_INT32, addr, NULL);
+    HAL_PROPERTY_TYPE_INT32, addr, "info.bus",
+    HAL_PROPERTY_TYPE_STRING, "usb_device", NULL);
 
   if (device)
     {
@@ -276,6 +272,23 @@
   return FALSE;
 }
 
+static gboolean
+hf_usb2_devd_notify (const char *system,
+		     const char *subsystem,
+		     const char *type,
+		     const char *data)
+{
+  if (! data || strcmp(system, "DEVFS") || strcmp(subsystem, "CDEV") ||
+      (strcmp(type, "CREATE") && strcmp(type, "DESTROY")))
+    return FALSE;
+
+  if (! strncmp(data, "cdev=ugen", strlen("cdev=ugen")) ||
+      ! strncmp(data, "cdev=usb", strlen("cdev=usb")))
+    return TRUE;
+
+  return FALSE;
+}
+
 HFHandler hf_usb2_handler = {
   .privileged_init	= hf_usb2_privileged_init,
   .probe		= hf_usb2_probe
@@ -283,5 +296,6 @@
 
 HFDevdHandler hf_usb2_devd_handler = {
   .add =	hf_usb2_devd_add,
-  .remove =	hf_usb2_devd_remove
+  .remove =	hf_usb2_devd_remove,
+  .notify =     hf_usb2_devd_notify
 };
