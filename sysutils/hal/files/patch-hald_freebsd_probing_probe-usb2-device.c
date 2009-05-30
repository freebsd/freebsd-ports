--- hald/freebsd/probing/probe-usb2-device.c.orig	2009-05-30 03:09:03.000000000 -0400
+++ hald/freebsd/probing/probe-usb2-device.c	2009-05-30 03:10:48.000000000 -0400
@@ -0,0 +1,208 @@
+/***************************************************************************
+ * CVSID: $Id$
+ *
+ * probe-usb2-device.c : USB2 Device poller
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
+#include <sys/param.h>
+#include <sys/types.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
+
+#include <libusb20_desc.h>
+#include <libusb20.h>
+#if __FreeBSD_version >= 800064
+#include <dev/usb/usb_ioctl.h>
+#else
+#include <dev/usb2/include/usb2_standard.h>
+#include <dev/usb2/include/usb2_ioctl.h>
+#endif
+
+#include "../libprobe/hfp.h"
+
+int
+main(int argc, char **argv)
+{
+  struct libusb20_backend *pbe = NULL;
+  struct libusb20_device *pdev = NULL;
+  char *busstr, *addrstr;
+  int bus, addr;
+
+  if (! hfp_init(argc, argv))
+    goto end;
+
+  pbe = libusb20_be_alloc_default();
+  if (pbe == NULL)
+    goto end;
+
+  busstr = getenv("HAL_PROP_USB_DEVICE_BUS_NUMBER");
+  if (! busstr)
+    goto end;
+
+  addrstr = getenv("HAL_PROP_USB_DEVICE_PORT_NUMBER");
+  if (! addrstr)
+    goto end;
+
+  bus = atoi(busstr);
+  addr = atoi(addrstr);
+
+  while ((pdev = libusb20_be_device_foreach(pbe, pdev)))
+    {
+      struct LIBUSB20_DEVICE_DESC_DECODED *ddesc;
+      struct LIBUSB20_CONFIG_DESC_DECODED *cdesc;
+#if __FreeBSD_version >= 800092
+      struct usb_device_info di;
+#else
+      struct usb2_device_info di;
+#endif
+      struct libusb20_config *pcfg = NULL;
+      int curr_config;
+      int bcdspeed = 0;
+      uint8_t temp_string[256];
+      double speed = 0.0;
+      double version = 1.0;
+
+      if (libusb20_dev_get_bus_number(pdev) != bus ||
+          libusb20_dev_get_address(pdev) != addr)
+        continue;
+
+      if (libusb20_dev_open(pdev, 0))
+        continue;
+
+      ddesc = libusb20_dev_get_device_desc(pdev);
+      curr_config = libusb20_dev_get_config_index(pdev);
+      pcfg = libusb20_dev_alloc_config(pdev, curr_config);
+      cdesc = &(pcfg->desc);
+
+      if (pcfg == NULL || libusb20_dev_get_info(pdev, &di))
+        {
+          free(pcfg);
+	  continue;
+	}
+
+      memset(temp_string, 0, sizeof(temp_string));
+
+      if (cdesc->iConfiguration !=0)
+        libusb20_dev_req_string_simple_sync(pdev, cdesc->iConfiguration,
+          temp_string, sizeof(temp_string));
+
+      libhal_device_set_property_string(hfp_ctx, hfp_udi,
+        "usb_device.configuration", (char *) temp_string, &hfp_error);
+      libhal_device_set_property_int(hfp_ctx, hfp_udi,
+        "usb_device.configuration_value", cdesc->bConfigurationValue,
+	&hfp_error);
+      libhal_device_set_property_int(hfp_ctx, hfp_udi,
+        "usb_device.num_configurations", ddesc->bNumConfigurations,
+	&hfp_error);
+      libhal_device_set_property_int(hfp_ctx, hfp_udi,
+        "usb_device.device_class", di.udi_class, &hfp_error);
+      libhal_device_set_property_int(hfp_ctx, hfp_udi,
+        "usb_device.device_subclass", di.udi_subclass, &hfp_error);
+      libhal_device_set_property_int(hfp_ctx, hfp_udi,
+        "usb_device.device_protocol", di.udi_protocol, &hfp_error);
+      libhal_device_set_property_bool(hfp_ctx, hfp_udi,
+        "usb_device.is_self_powered",
+	di.udi_power == 0 ? TRUE : FALSE, &hfp_error);
+      libhal_device_set_property_bool(hfp_ctx, hfp_udi,
+        "usb_device.can_wake_up",
+	(cdesc->bmAttributes & UC_REMOTE_WAKEUP) != 0 ? TRUE : FALSE,
+	&hfp_error);
+      libhal_device_set_property_int(hfp_ctx, hfp_udi,
+        "usb_device.max_power", di.udi_power, &hfp_error);
+      libhal_device_set_property_int(hfp_ctx, hfp_udi,
+        "usb_device.num_interfaces", pcfg->num_interface, &hfp_error);
+      libhal_device_set_property_int(hfp_ctx, hfp_udi,
+        "usb_device.num_ports", di.udi_nports, &hfp_error);
+
+      switch (libusb20_dev_get_speed(pdev))
+        {
+          case LIBUSB20_SPEED_LOW:
+            speed = 1.5;
+	    bcdspeed = 0x00150;
+	    break;
+	  case LIBUSB20_SPEED_FULL:
+	    speed = 12.0;
+	    bcdspeed = 0x01200;
+	    break;
+	  case LIBUSB20_SPEED_HIGH:
+	    speed = 480.0;
+	    bcdspeed = 0x48000;
+	    break;
+	  case LIBUSB20_SPEED_SUPER:
+	    speed = 4800.0;
+	    bcdspeed = 0x480000;
+	    break;
+	  default:
+	    ;
+	}
+
+      libhal_device_set_property_double(hfp_ctx, hfp_udi, "usb_device.speed",
+        speed, &hfp_error);
+      libhal_device_set_property_int(hfp_ctx, hfp_udi, "usb_device.speed_bcd",
+        bcdspeed, &hfp_error);
+
+      switch (ddesc->bcdUSB)
+        {
+          case UD_USB_2_0:
+            version = 2.0;
+	    break;
+	  case UD_USB_3_0:
+	    version = 3.0;
+	    break;
+	  default:
+	    version = 1.0;
+	    break;
+	}
+
+      libhal_device_set_property_double(hfp_ctx, hfp_udi,
+        "usb_device.version", version, &hfp_error);
+      libhal_device_set_property_int(hfp_ctx, hfp_udi,
+        "usb_device.product_id", di.udi_productNo, &hfp_error);
+      libhal_device_set_property_int(hfp_ctx, hfp_udi,
+        "usb_device.vendor_id", di.udi_vendorNo, &hfp_error);
+      libhal_device_set_property_int(hfp_ctx, hfp_udi,
+        "usb_device.device_revision_bcd", ddesc->bcdUSB, &hfp_error);
+      libhal_device_set_property_string(hfp_ctx, hfp_udi,
+        "usb_device.serial", di.udi_serial, &hfp_error);
+      libhal_device_set_property_string(hfp_ctx, hfp_udi,
+        "usb_device.product", di.udi_product, &hfp_error);
+      libhal_device_set_property_string(hfp_ctx, hfp_udi,
+        "usb_device.vendor", di.udi_vendor, &hfp_error);
+
+      libhal_device_set_property_string(hfp_ctx, hfp_udi,
+        "info.product", di.udi_product, &hfp_error);
+      libhal_device_set_property_string(hfp_ctx, hfp_udi,
+        "info.vendor", di.udi_vendor, &hfp_error);
+
+      libusb20_dev_close(pdev);
+      free(pcfg);
+    }
+end:
+  if (pbe)
+    libusb20_be_free(pbe);
+
+  return 0;
+}
