--- ./hald/freebsd/hf-usb2.c.orig	2009-08-24 14:42:29.000000000 +0200
+++ ./hald/freebsd/hf-usb2.c	2013-10-23 13:10:36.639758556 +0200
@@ -22,7 +22,7 @@
  **************************************************************************/
 
 #ifdef HAVE_CONFIG_H
-#  include <config.h>
+#include <config.h>
 #endif
 
 #include <string.h>
@@ -42,246 +42,213 @@
 static struct libusb20_backend *hf_usb2_be = NULL;
 
 static void
-hf_usb2_copy_parent (HalDevice *parent,
-		     const char *key,
-		     gpointer user_data)
+hf_usb2_probe_interfaces(HalDevice * parent)
 {
-  HalDevice *device;
+	int num_interfaces;
+	int i;
 
-  g_return_if_fail(HAL_IS_DEVICE(parent));
-  g_return_if_fail(HAL_IS_DEVICE(user_data));
+	g_return_if_fail(HAL_IS_DEVICE(parent));
 
-  device = HAL_DEVICE(user_data);
-
-  if (! strncmp(key, "usb_device.", strlen("usb_device.")))
-    hal_device_copy_property(parent, key, device, key);
+	if (hal_device_property_get_bool(parent, "info.ignore"))
+		return;
+
+	num_interfaces = hal_device_property_get_int(parent,
+	    "usb_device.num_interfaces");
+
+	for (i = 0; i < num_interfaces; i++) {
+		HalDevice *device;
+
+		device = hf_device_new(parent);
+
+		hal_device_property_set_string(device, "info.subsystem", "usb");
+		hal_device_property_set_int(device, "usb.interface.number", i);
+		hal_device_copy_property(parent, "info.product", device, "info.product");
+		hal_device_copy_property(parent, "info.vendor", device, "info.vendor");
+		hal_device_merge_with_rewrite(device, parent, "usb.", "usb_device.");
+
+		if (hf_device_preprobe(device)) {
+			const char *driver, *devname;
+
+			hf_runner_run_sync(device, 0, "hald-probe-usb2-interface", NULL);
+
+			devname = hal_device_property_get_string(device,
+			    "usb.freebsd.devname");
+			if (devname)
+				hf_devtree_device_set_name(device, devname);
+
+			driver = hal_device_property_get_string(device, "freebsd.driver");
+			if (driver) {
+				if (!strcmp(driver, "ukbd"))
+					hf_device_set_input(device, "keyboard", "keys", NULL);
+				else if (!strcmp(driver, "ums") || !strcmp(driver, "atp")) {
+					hf_device_set_input(device, "mouse", NULL, devname);
+					hf_runner_run_sync(device, 0, "hald-probe-mouse", NULL);
+				} else if (!strcmp(driver, "uhid")) {
+					hal_device_property_set_string(device, "info.category",
+					    "hiddev");
+					hal_device_add_capability(device, "hiddev");
+					hf_device_property_set_string_printf(device, "hiddev.device",
+					    "/dev/%s", devname);
+					hal_device_copy_property(device, "info.product", device,
+					    "hiddev.product");
+					hf_runner_run_sync(device, 0, "hald-probe-hiddev", NULL);
+				} else if (!strcmp(driver, "ldev")) {
+					/* Linux driver (webcam) */
+
+					/*
+		                         * XXX This is a hack.  Currently, all ldev devices are
+				         * webcams.  That may not always be the case.  Hopefully,
+				         * when other Linux driver support is added, there will be
+				         * a sysctl or some other way to determine device class.
+			                 */
+					hf_usb_add_webcam_properties(device);
+				} else if (!strcmp(driver, "pwc")) {
+					/* Phillips Web Cam */
+					hf_usb_add_webcam_properties(device);
+				}
+			} else {
+				/* Try and detect webcamd devices. */
+				hf_runner_run_sync(device, 0, "hald-probe-video4linux", NULL);
+			}
+
+			hf_usb_device_compute_udi(device);
+			hf_device_add(device);
+
+			/*
+			 * The SCSI bus could already exist; make it a child of
+			 * this USB interface.
+			 */
+			if (driver && !strcmp(driver, "umass")) {
+				HalDevice *scsi_bus;
+				scsi_bus = hf_device_store_match(hald_get_gdl(),
+				    "scsi_host.freebsd.driver", HAL_PROPERTY_TYPE_STRING, driver,
+				    "scsi_host.freebsd.unit", HAL_PROPERTY_TYPE_INT32, hal_device_property_get_int(device, "freebsd.unit"), NULL);
+				if (scsi_bus)
+					hal_device_property_set_string(scsi_bus, "info.parent", hal_device_get_udi(device));
+			}
+		}
+	}
 }
 
 static void
-hf_usb2_probe_interfaces(HalDevice *parent)
+hf_usb2_probe_device(HalDevice * parent, int bus, int addr)
 {
-  int num_interfaces;
-  int i;
+	HalDevice *device;
 
-  g_return_if_fail(HAL_IS_DEVICE(parent));
+	g_return_if_fail(HAL_IS_DEVICE(parent));
 
-  if (hal_device_property_get_bool(parent, "info.ignore"))
-    return;
+	device = hf_device_new(parent);
 
-  num_interfaces = hal_device_property_get_int(parent,
-    "usb_device.num_interfaces");
-
-  for (i = 0; i < num_interfaces; i++)
-    {
-      HalDevice *device;
-
-      device = hf_device_new(parent);
-
-      hal_device_property_set_string(device, "info.subsystem", "usb");
-      hal_device_property_set_int(device, "usb.interface.number", i);
-      hal_device_property_foreach(parent, hf_usb2_copy_parent, device);
-      hal_device_copy_property(parent, "info.product", device, "info.product");
-      hal_device_copy_property(parent, "info.vendor", device, "info.vendor");
-
-      if (hf_device_preprobe(device))
-        {
-          const char *driver, *devname;
-
-          hf_runner_run_sync(device, 0, "hald-probe-usb2-interface", NULL);
-
-	  devname = hal_device_property_get_string(device,
-            "usb.freebsd.devname");
-	  if (devname)
-            hf_devtree_device_set_name(device, devname);
-
-	  driver = hal_device_property_get_string(device, "freebsd.driver");
-	  if (driver)
-            {
-	      if (! strcmp(driver, "ukbd"))
-                hf_device_set_input(device, "keyboard", NULL);
-	      else if (! strcmp(driver, "ums"))
-                {
-                  hf_device_set_input(device, "mouse", devname);
-	          hf_runner_run_sync(device, 0, "hald-probe-mouse", NULL);
-	        }
-	      else if (! strcmp(driver, "uhid"))
-                {
-                  hal_device_property_set_string(device, "info.category",
-                    "hiddev");
-	          hal_device_add_capability(device, "hiddev");
-	          hf_device_property_set_string_printf(device, "hiddev.device",
-                    "/dev/%s", devname);
-	          hal_device_copy_property(device, "info.product", device,
-                    "hiddev.product");
-	          hf_runner_run_sync(device, 0, "hald-probe-hiddev", NULL);
-	        }
-	      else if (! strcmp(driver, "ldev"))
-                {
-                  /* Linux driver (webcam) */
-
-	          /*
-                   * XXX This is a hack.  Currently, all ldev devices are
-		   * webcams.  That may not always be the case.  Hopefully,
-		   * when other Linux driver support is added, there will be
-		   * a sysctl or some other way to determine device class.
-	           */
-                  hf_usb_add_webcam_properties(device);
-	        }
-	      else if (! strcmp(driver, "pwc"))
-                {
-                  /* Phillips Web Cam */
-                  hf_usb_add_webcam_properties(device);
-	        }
-	    }
+	hal_device_property_set_string(device, "info.subsystem", "usb_device");
+	hal_device_property_set_int(device, "usb_device.bus_number", bus);
+	hal_device_property_set_int(device, "usb_device.level_number", 1);
+	hal_device_property_set_int(device, "usb_device.port_number", addr);
 
-	  hf_usb_device_compute_udi(device);
-	  hf_device_add(device);
+	if (hf_device_preprobe(device)) {
+		hf_runner_run_sync(device, 0, "hald-probe-usb2-device", NULL);
+		hf_usb_device_compute_udi(device);
+		hf_device_add(device);
+		hf_usb2_probe_interfaces(device);
 	}
-    }
 }
 
 static void
-hf_usb2_probe_device (HalDevice *parent, int bus, int addr)
+hf_usb2_privileged_init(void)
 {
-  HalDevice *device;
-
-  g_return_if_fail(HAL_IS_DEVICE(parent));
-
-  device = hf_device_new(parent);
+	hf_usb2_be = libusb20_be_alloc_default();
+	if (hf_usb2_be == NULL)
+		HAL_INFO(("unable to open USB backend: %s", g_strerror(errno)));
+}
 
-  hal_device_property_set_string(device, "info.subsystem", "usb_device");
-  hal_device_property_set_int(device, "usb_device.bus_number", bus);
-  hal_device_property_set_int(device, "usb_device.level_number", addr - 1);
-  hal_device_property_set_int(device, "usb_device.port_number", addr);
+static void
+hf_usb2_new_device(int bus, int addr)
+{
+	HalDevice *parent;
 
-  if (hf_device_preprobe(device))
-    {
-      hf_runner_run_sync(device, 0, "hald-probe-usb2-device", NULL);
-      hf_usb_device_compute_udi(device);
+	parent = hf_devtree_find_from_info(hald_get_gdl(), "usbus", bus);
 
-      hf_device_add(device);
-    }
-  else
-    return;
+	if (!parent || hal_device_property_get_bool(parent, "info.ignore"))
+		return;
 
-  hf_usb2_probe_interfaces(device);
+	hf_usb2_probe_device(parent, bus, addr);
 }
 
 static void
-hf_usb2_privileged_init (void)
+hf_usb2_probe(void)
 {
-  hf_usb2_be = libusb20_be_alloc_default();
-  if (hf_usb2_be == NULL)
-    HAL_INFO(("unable to open USB backend: %s", g_strerror(errno)));
-}
+	struct libusb20_device *pdev = NULL;
 
-static void
-hf_usb2_probe (void)
-{
-  struct libusb20_device *pdev = NULL;
+	if (hf_usb2_be == NULL)
+		return;
 
-  if (hf_usb2_be == NULL)
-    return;
+	while ((pdev = libusb20_be_device_foreach(hf_usb2_be, pdev))) {
+		hf_usb2_new_device(libusb20_dev_get_bus_number(pdev),
+		    libusb20_dev_get_address(pdev));
+	}
 
-  while ((pdev = libusb20_be_device_foreach(hf_usb2_be, pdev)))
-    {
-      HalDevice *parent;
-      int bus, addr;
-
-      bus = libusb20_dev_get_bus_number(pdev);
-      addr = libusb20_dev_get_address(pdev);
-
-      if (addr == 1)
-        parent = hf_devtree_find_parent_from_info(hald_get_gdl(), "usbus", bus);
-      else
-        parent = hf_device_store_match(hald_get_gdl(), "usb_device.bus_number",
-          HAL_PROPERTY_TYPE_INT32, bus, "usb_device.port_number",
-	  HAL_PROPERTY_TYPE_INT32, addr - 1, NULL);
-      if (! parent || hal_device_property_get_bool(parent, "info.ignore"))
-        continue;
+	libusb20_be_free(hf_usb2_be);
+	hf_usb2_be = NULL;
+}
 
-      hf_usb2_probe_device(parent, bus, addr);
-    }
+static	gboolean
+hf_usb2_devd_notify(const char *system,
+    const char *subsystem,
+    const char *type,
+    const char *data)
+{
+	const char *ugen;
+	int bus;
+	int addr;
+
+	if (!data || strcmp(system, "USB") || strcmp(subsystem, "DEVICE") ||
+	    (strcmp(type, "ATTACH") && strcmp(type, "DETACH")))
+		return FALSE;
+
+	ugen = strstr(data, "ugen=");
+	if (ugen == NULL) {
+		/*
+		 * The following case is not required in
+		 * FreeBSD 8-stable and newer:
+		 */
+		ugen = strstr(data, "cdev=");
+		if (ugen == NULL)
+			return FALSE;
+
+		if (sscanf(ugen, "cdev=ugen%i.%i", &bus, &addr) != 2)
+			return FALSE;
+	} else {
+		if (sscanf(ugen, "ugen=ugen%i.%i", &bus, &addr) != 2)
+			return FALSE;
+	}
 
-  libusb20_be_free(hf_usb2_be);
-  hf_usb2_be = NULL;
-}
+	if (strcmp(type, "ATTACH") == 0) {
 
-static gboolean
-hf_usb2_devd_add (const char *name,
-		  GHashTable *params,
-		  GHashTable *at,
-		  const char *parent)
-{
-  HalDevice *parent_device;
-  int bus, addr, pbus, paddr;
+		HAL_INFO(("received devd attach event, device %s", data));
 
-  if (strncmp(name, "ugen", strlen("ugen")))
-    return FALSE;
-  else if (strncmp(parent, "ugen", strlen("ugen")))
-    return TRUE;
-
-  if (sscanf(name, "ugen%i.%i", &bus, &addr) != 2)
-    return FALSE;
-
-  if (sscanf(parent, "ugen%i.%i", &pbus, &paddr) != 2)
-    return FALSE;
-
-  HAL_INFO(("received devd add event for device '%s' with parent '%s'",
-           name, parent));
-
-  parent_device = hf_device_store_match(hald_get_gdl(),
-    "usb_device.bus_number", HAL_PROPERTY_TYPE_INT32, pbus,
-    "usb_device.port_number", HAL_PROPERTY_TYPE_INT32, paddr, NULL);
-
-  if (parent_device && ! hal_device_property_get_bool(parent_device,
-      "info.ignore"))
-    {
-      hf_usb2_probe_device(parent_device, bus, addr);
-      return TRUE;
-    }
+		hf_usb2_new_device(bus, addr);
+	}
+	if (strcmp(type, "DETACH") == 0) {
 
-  return FALSE;
-}
+		HalDevice *device;
 
-static gboolean
-hf_usb2_devd_remove (const char *name,
-		     GHashTable *params,
-		     GHashTable *at,
-		     const char *parent)
-{
-  HalDevice *device;
-  int bus, addr;
+		HAL_INFO(("received devd detach event, device %s", data));
 
-  if (strncmp(name, "ugen", strlen("ugen")))
-    return FALSE;
-  else if (strncmp(parent, "ugen", strlen("ugen")))
-    return TRUE;
-
-  if (sscanf(name, "ugen%i.%i", &bus, &addr) != 2)
-    return FALSE;
-
-  HAL_INFO(("received devd remove event, device %s", name));
-
-  device = hf_device_store_match(hald_get_gdl(), "usb_device.bus_number",
-    HAL_PROPERTY_TYPE_INT32, bus, "usb_device.port_number",
-    HAL_PROPERTY_TYPE_INT32, addr, NULL);
-
-  if (device)
-    {
-      hf_device_remove_tree(device);
-      return TRUE;
-    }
+		device = hf_device_store_match(hald_get_gdl(),
+		    "usb_device.bus_number", HAL_PROPERTY_TYPE_INT32, bus,
+		    "usb_device.port_number", HAL_PROPERTY_TYPE_INT32, addr,
+		    "info.bus", HAL_PROPERTY_TYPE_STRING, "usb_device", NULL);
 
-  return FALSE;
+		if (device)
+			hf_device_remove_tree(device);
+	}
+	return TRUE;
 }
 
 HFHandler hf_usb2_handler = {
-  .privileged_init	= hf_usb2_privileged_init,
-  .probe		= hf_usb2_probe
+	.privileged_init = hf_usb2_privileged_init,
+	.probe = hf_usb2_probe
 };
 
 HFDevdHandler hf_usb2_devd_handler = {
-  .add =	hf_usb2_devd_add,
-  .remove =	hf_usb2_devd_remove
+	.notify = hf_usb2_devd_notify
 };
