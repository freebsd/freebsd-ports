--- ./hald/freebsd/hf-memcard.c.orig	2013-10-22 01:49:10.228430727 +0200
+++ ./hald/freebsd/hf-memcard.c	2013-10-22 01:48:06.869268391 +0200
@@ -0,0 +1,106 @@
+/***************************************************************************
+ * CVSID: $Id$
+ *
+ * hf-memcard.c : memory card support
+ *
+ * Copyright (C) 2013 Alberto Villa <avilla@FreeBSD.org>
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
+
+#include "../logger.h"
+
+#include "hf-memcard.h"
+#include "hf-block.h"
+#include "hf-devtree.h"
+#include "hf-storage.h"
+#include "hf-util.h"
+
+static HalDevice *
+hf_memcard_block_device_new (HalDevice *parent,
+                             const char *driver,
+                             int unit,
+                             const char *drive_type)
+{
+  HalDevice *device;
+  char devname[16];
+
+  snprintf(devname, sizeof(devname), "%s%d", driver, unit);
+
+  g_return_val_if_fail(HAL_IS_DEVICE(parent), NULL);
+  g_return_val_if_fail(devname != NULL, NULL);
+
+  device = hf_device_new(parent);
+
+  hf_devtree_device_set_name(device, devname);
+  hf_block_device_enable(device, devname);
+
+  hf_storage_device_enable(device);
+
+  hal_device_copy_property(parent, "info.subsystem", device, "storage.bus");
+  hal_device_property_set_string(device, "storage.originating_device", hal_device_get_udi(parent));
+  hal_device_property_set_bool(device, "storage.removable", TRUE);
+  hal_device_property_set_bool(device, "storage.media_check_enabled", TRUE);
+  hal_device_property_set_bool(device, "storage.removable.support_async_notification", FALSE);
+  hal_device_property_set_bool(device, "storage.hotpluggable", TRUE);
+  if (drive_type)
+    {
+      hal_device_property_set_string(device, "storage.drive_type", drive_type);
+    }
+
+  if (hf_device_preprobe(device))
+    {
+      hf_block_device_complete(device, device, FALSE);
+      hf_device_add(device);
+      hf_storage_device_probe(device, FALSE);
+    }
+
+  return device;
+}
+
+void
+hf_mmc_host_set_properties (HalDevice *device)
+{
+  hal_device_property_set_string(device, "info.subsystem", "mmc_host");
+  hal_device_copy_property(device, "freebsd.unit", device, "mmc_host.host");
+}
+
+void
+hf_mmc_set_properties (HalDevice *device)
+{
+  HalDevice *block_device;
+
+  hal_device_property_set_string(device, "info.subsystem", "mmc");
+
+  hf_memcard_block_device_new(device,
+                              hal_device_property_get_string(device, "freebsd.driver"),
+                              hal_device_property_get_int(device, "freebsd.unit"),
+                              "sd_mmc");
+
+  /* This information belongs to the block device. */
+  hal_device_property_remove(device, "freebsd.device_file");
+  hal_device_property_remove(device, "freebsd.driver");
+  hal_device_property_remove(device, "freebsd.unit");
+}
