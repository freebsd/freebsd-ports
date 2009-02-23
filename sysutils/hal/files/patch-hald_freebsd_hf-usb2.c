--- hald/freebsd/hf-usb2.c.orig	2009-02-17 18:58:44.000000000 -0500
+++ hald/freebsd/hf-usb2.c	2009-02-17 23:22:47.000000000 -0500
@@ -0,0 +1,287 @@
+/***************************************************************************
+ * CVSID: $Id$
+ *
+ * hf-usb.c : USB support
+ *
+ * Copyright (C) 2009 Joe Marcus Clarke <marcus@FreeBSD.org>
+ *
+ * This program is free software; you can redistribute it and/or modify
+ * it under the terms of the GNU General Public License as published by
+ * the Free Software Foundation; either version 2 of the License, or
+ * (at your option) any later version.
+ *
+ * This program is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ * GNU General Public License for more details.
+ *
+ * You should have received a copy of the GNU General Public License
+ * along with this program; if not, write to the Free Software
+ * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
+ *
+ **************************************************************************/
+
+#ifdef HAVE_CONFIG_H
+#  include <config.h>
+#endif
+
+#include <string.h>
+#include <errno.h>
+#include <stdlib.h>
+#include <unistd.h>
+#include <libusb20.h>
+
+#include "../logger.h"
+#include "../osspec.h"
+
+#include "hf-usb.h"
+#include "hf-usb2.h"
+#include "hf-devtree.h"
+#include "hf-util.h"
+
+static struct libusb20_backend *hf_usb2_be = NULL;
+
+static void
+hf_usb2_copy_parent (HalDevice *parent,
+		     const char *key,
+		     gpointer user_data)
+{
+  HalDevice *device;
+
+  g_return_if_fail(HAL_IS_DEVICE(parent));
+  g_return_if_fail(HAL_IS_DEVICE(user_data));
+
+  device = HAL_DEVICE(user_data);
+
+  if (! strncmp(key, "usb_device.", strlen("usb_device.")))
+    hal_device_copy_property(parent, key, device, key);
+}
+
+static void
+hf_usb2_probe_interfaces(HalDevice *parent)
+{
+  int num_interfaces;
+  int i;
+
+  g_return_if_fail(HAL_IS_DEVICE(parent));
+
+  if (hal_device_property_get_bool(parent, "info.ignore"))
+    return;
+
+  num_interfaces = hal_device_property_get_int(parent,
+    "usb_device.num_interfaces");
+
+  for (i = 0; i < num_interfaces; i++)
+    {
+      HalDevice *device;
+
+      device = hf_device_new(parent);
+
+      hal_device_property_set_string(device, "info.subsystem", "usb");
+      hal_device_property_set_int(device, "usb.interface.number", i);
+      hal_device_property_foreach(parent, hf_usb2_copy_parent, device);
+      hal_device_copy_property(parent, "info.product", device, "info.product");
+      hal_device_copy_property(parent, "info.vendor", device, "info.vendor");
+
+      if (hf_device_preprobe(device))
+        {
+          const char *driver, *devname;
+
+          hf_runner_run_sync(device, 0, "hald-probe-usb2-interface", NULL);
+
+	  devname = hal_device_property_get_string(device,
+            "usb.freebsd.devname");
+	  if (devname)
+            hf_devtree_device_set_name(device, devname);
+
+	  driver = hal_device_property_get_string(device, "freebsd.driver");
+	  if (driver)
+            {
+	      if (! strcmp(driver, "ukbd"))
+                hf_device_set_input(device, "keyboard", devname);
+	      else if (! strcmp(driver, "ums"))
+                {
+                  hf_device_set_input(device, "mouse", devname);
+	          hf_runner_run_sync(device, 0, "hald-probe-mouse", NULL);
+	        }
+	      else if (! strcmp(driver, "uhid"))
+                {
+                  hal_device_property_set_string(device, "info.category",
+                    "hiddev");
+	          hal_device_add_capability(device, "hiddev");
+	          hf_device_property_set_string_printf(device, "hiddev.device",
+                    "/dev/%s", devname);
+	          hal_device_copy_property(device, "info.product", device,
+                    "hiddev.product");
+	          hf_runner_run_sync(device, 0, "hald-probe-hiddev", NULL);
+	        }
+	      else if (! strcmp(driver, "ldev"))
+                {
+                  /* Linux driver (webcam) */
+
+	          /*
+                   * XXX This is a hack.  Currently, all ldev devices are
+		   * webcams.  That may not always be the case.  Hopefully,
+		   * when other Linux driver support is added, there will be
+		   * a sysctl or some other way to determine device class.
+	           */
+                  hf_usb_add_webcam_properties(device);
+	        }
+	      else if (! strcmp(driver, "pwc"))
+                {
+                  /* Phillips Web Cam */
+                  hf_usb_add_webcam_properties(device);
+	        }
+	    }
+
+	  hf_usb_device_compute_udi(device);
+	  hf_device_add(device);
+	}
+    }
+}
+
+static void
+hf_usb2_probe_device (HalDevice *parent, int bus, int addr)
+{
+  HalDevice *device;
+
+  g_return_if_fail(HAL_IS_DEVICE(parent));
+
+  device = hf_device_new(parent);
+
+  hal_device_property_set_string(device, "info.subsystem", "usb_device");
+  hal_device_property_set_int(device, "usb_device.bus_number", bus);
+  hal_device_property_set_int(device, "usb_device.level_number", addr - 1);
+  hal_device_property_set_int(device, "usb_device.port_number", addr);
+
+  if (hf_device_preprobe(device))
+    {
+      hf_runner_run_sync(device, 0, "hald-probe-usb2-device", NULL);
+      hf_usb_device_compute_udi(device);
+
+      hf_device_add(device);
+    }
+  else
+    return;
+
+  hf_usb2_probe_interfaces(device);
+}
+
+static void
+hf_usb2_privileged_init (void)
+{
+  hf_usb2_be = libusb20_be_alloc_default();
+  if (hf_usb2_be == NULL)
+    HAL_INFO(("unable to open USB backend: %s", g_strerror(errno)));
+}
+
+static void
+hf_usb2_probe (void)
+{
+  struct libusb20_device *pdev = NULL;
+
+  if (hf_usb2_be == NULL)
+    return;
+
+  while ((pdev = libusb20_be_device_foreach(hf_usb2_be, pdev)))
+    {
+      HalDevice *parent;
+      int bus, addr;
+
+      bus = libusb20_dev_get_bus_number(pdev);
+      addr = libusb20_dev_get_address(pdev);
+
+      if (addr == 1)
+        parent = hf_devtree_find_parent_from_info(hald_get_gdl(), "usbus", bus);
+      else
+        parent = hf_device_store_match(hald_get_gdl(), "usb_device.bus_number",
+          HAL_PROPERTY_TYPE_INT32, bus, "usb_device.port_number",
+	  HAL_PROPERTY_TYPE_INT32, addr - 1, NULL);
+      if (! parent || hal_device_property_get_bool(parent, "info.ignore"))
+        continue;
+
+      hf_usb2_probe_device(parent, bus, addr);
+    }
+
+  libusb20_be_free(hf_usb2_be);
+  hf_usb2_be = NULL;
+}
+
+static gboolean
+hf_usb2_devd_add (const char *name,
+		  GHashTable *params,
+		  GHashTable *at,
+		  const char *parent)
+{
+  HalDevice *parent_device;
+  int bus, addr, pbus, paddr;
+
+  if (strncmp(name, "ugen", strlen("ugen")))
+    return FALSE;
+  else if (strncmp(parent, "ugen", strlen("ugen")))
+    return TRUE;
+
+  if (sscanf(name, "ugen%i.%i", &bus, &addr) != 2)
+    return FALSE;
+
+  if (sscanf(parent, "ugen%i.%i", &pbus, &paddr) != 2)
+    return FALSE;
+
+  HAL_INFO(("received devd add event for device '%s' with parent '%s'",
+           name, parent));
+
+  parent_device = hf_device_store_match(hald_get_gdl(),
+    "usb_device.bus_number", HAL_PROPERTY_TYPE_INT32, pbus,
+    "usb_device.port_number", HAL_PROPERTY_TYPE_INT32, paddr, NULL);
+
+  if (parent_device && ! hal_device_property_get_bool(parent_device,
+      "info.ignore"))
+    {
+      hf_usb2_probe_device(parent_device, bus, addr);
+      return TRUE;
+    }
+
+  return FALSE;
+}
+
+static gboolean
+hf_usb2_devd_remove (const char *name,
+		     GHashTable *params,
+		     GHashTable *at,
+		     const char *parent)
+{
+  HalDevice *device;
+  int bus, addr;
+
+  if (strncmp(name, "ugen", strlen("ugen")))
+    return FALSE;
+  else if (strncmp(parent, "ugen", strlen("ugen")))
+    return TRUE;
+
+  if (sscanf(name, "ugen%i.%i", &bus, &addr) != 2)
+    return FALSE;
+
+  HAL_INFO(("received devd remove event, device %s", name));
+
+  device = hf_device_store_match(hald_get_gdl(), "usb_device.bus_number",
+    HAL_PROPERTY_TYPE_INT32, bus, "usb_device.port_number",
+    HAL_PROPERTY_TYPE_INT32, addr, NULL);
+
+  if (device)
+    {
+      hf_device_remove_tree(device);
+      return TRUE;
+    }
+
+  return FALSE;
+}
+
+HFHandler hf_usb2_handler = {
+  .privileged_init	= hf_usb2_privileged_init,
+  .probe		= hf_usb2_probe
+};
+
+HFDevdHandler hf_usb2_devd_handler = {
+  .add =	hf_usb2_devd_add,
+  .remove =	hf_usb2_devd_remove
+};
