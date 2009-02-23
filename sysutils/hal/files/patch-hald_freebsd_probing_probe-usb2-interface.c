--- hald/freebsd/probing/probe-usb2-interface.c.orig	2009-02-18 00:05:44.000000000 -0500
+++ hald/freebsd/probing/probe-usb2-interface.c	2009-02-18 00:08:34.000000000 -0500
@@ -0,0 +1,135 @@
+/***************************************************************************
+ * CVSID: $Id$
+ *
+ * probe-usb2-interface.c : USB2 Interface poller
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
+#include <sys/types.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
+
+#include <libusb20_desc.h>
+#include <libusb20.h>
+#include <dev/usb2/include/usb2_standard.h>
+#include <dev/usb2/include/usb2_ioctl.h>
+
+#include "../libprobe/hfp.h"
+
+int
+main(int argc, char **argv)
+{
+  struct libusb20_backend *pbe = NULL;
+  struct libusb20_device *pdev = NULL;
+  char *busstr, *addrstr, *ifacestr;
+  int bus, addr, iface;
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
+  ifacestr = getenv("HAL_PROP_USB_INTERFACE_NUMBER");
+  if (! ifacestr)
+    goto end;
+
+  bus = atoi(busstr);
+  addr = atoi(addrstr);
+  iface = atoi(ifacestr);
+
+  while ((pdev = libusb20_be_device_foreach(pbe, pdev)))
+    {
+      struct LIBUSB20_INTERFACE_DESC_DECODED *idesc;
+      struct libusb20_config *pcfg = NULL;
+      struct libusb20_interface *pif;
+      uint8_t temp_string[256];
+      char ifdrv[128];
+      int curr_config;
+
+      if (libusb20_dev_get_bus_number(pdev) != bus ||
+          libusb20_dev_get_address(pdev) != addr)
+        continue;
+
+      if (libusb20_dev_open(pdev, 0))
+        continue;
+
+      curr_config = libusb20_dev_get_config_index(pdev);
+      pcfg = libusb20_dev_alloc_config(pdev, curr_config);
+      if (! pcfg)
+        continue;
+
+      pif = pcfg->interface + iface;
+
+      idesc = &pif->desc;
+
+      libhal_device_set_property_int(hfp_ctx, hfp_udi,
+        "usb.interface.class", idesc->bInterfaceClass, &hfp_error);
+      libhal_device_set_property_int(hfp_ctx, hfp_udi,
+        "usb.interface.subclass", idesc->bInterfaceSubClass, &hfp_error);
+      libhal_device_set_property_int(hfp_ctx, hfp_udi,
+        "usb.interface.protocol", idesc->bInterfaceProtocol, &hfp_error);
+
+      memset(temp_string, 0, sizeof(temp_string));
+      if (idesc->iInterface != 0)
+        libusb20_dev_req_string_simple_sync(pdev, idesc->iInterface,
+          temp_string, sizeof(temp_string));
+
+      libhal_device_set_property_string(hfp_ctx, hfp_udi,
+        "usb.interface.description", (char *) temp_string, &hfp_error);
+
+      memset(ifdrv, 0, sizeof(ifdrv));
+      libusb20_dev_get_iface_desc(pdev, iface, ifdrv, sizeof(ifdrv));
+      if (ifdrv[0] != '\0')
+        {
+          char *ifdesc;
+
+	  ifdesc = strchr(ifdrv, ':');
+	  if (ifdesc)
+            {
+              *ifdesc = '\0';
+	      libhal_device_set_property_string(hfp_ctx, hfp_udi,
+                "usb.freebsd.devname", ifdrv, &hfp_error);
+	    }
+	}
+
+      free(pcfg);
+    }
+
+end:
+  if (pbe)
+    libusb20_be_free(pbe);
+
+  return 0;
+}
