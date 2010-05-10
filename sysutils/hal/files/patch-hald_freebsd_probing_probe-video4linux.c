--- hald/freebsd/probing/probe-video4linux.c.orig	2010-02-21 14:51:01.000000000 -0500
+++ hald/freebsd/probing/probe-video4linux.c	2010-02-21 14:54:51.000000000 -0500
@@ -0,0 +1,225 @@
+/***************************************************************************
+ * CVSID: $Id$
+ *
+ * probe-video4linux.c : Probe video4linux devices
+ * Adapted for FreeBSD by : Joe Marcus Clarke <marcus@FreeBSD.org>
+ *
+ * Copyright (C) 2007 Nokia Corporation
+ *
+ * Licensed under the Academic Free License version 2.1
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
+#include <sys/user.h>
+#include <sys/sysctl.h>
+#include <sys/time.h>
+#include <sys/ioctl.h>
+#include <linux/videodev.h>
+#include <linux/videodev2.h>
+#include <errno.h>
+#include <fcntl.h>
+#include <stdint.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
+#include <glib.h>
+
+#include "../libprobe/hfp.h"
+
+#define WEBCAMD_PID_FILE "/var/run/webcamd"
+#define V4B_DEVICES_MAX 10 /* XXX from video4bsd.h */
+
+static int
+hfp_v4l_get_unit (int bus, int addr)
+{
+	int i;
+	pid_t pid;
+	int mib[4];
+	char *endptr;
+	char *pidf = NULL;
+	char *contents = NULL;
+	gsize len;
+
+	for (i = 0; i < V4B_DEVICES_MAX; i++) {
+		pidf = g_strdup_printf ("%s.%i.%i.%i.pid", WEBCAMD_PID_FILE, bus, addr, i);
+		if (g_file_test (pidf, G_FILE_TEST_EXISTS))
+			break;
+		g_free (pidf);
+		pidf = NULL;
+	}
+
+	if (pidf == NULL)
+		return -1;
+
+	if (! g_file_get_contents (pidf, &contents, &len, NULL)) {
+		g_free (pidf);
+		return -1;
+	}
+
+	g_free (pidf);
+
+	pid = (int) strtol (contents, &endptr, 10);
+	if (endptr == contents) {
+		g_free (contents);
+		return -1;
+	}
+	g_free (contents);
+
+	len = 4;
+	sysctlnametomib ("kern.proc.pid", mib, &len);
+
+	len = sizeof(struct kinfo_proc);
+	mib[3] = pid;
+
+	/* This is just a rough test. */
+	if (sysctl (mib, 4, NULL, &len, NULL, 0) == -1)
+		return -1;
+
+	return i;
+}
+
+int
+main (int argc, char **argv)
+{
+	int ret = 1;
+	int fd = -1;
+	int unit = -1;
+	int bus = -1;
+	int addr = -1;
+	int intf = -1;
+	char *device_file = NULL;
+	char *busstr;
+	char *addrstr;
+	char *intfstr;
+	struct video_capability v1cap;
+	struct v4l2_capability v2cap;
+	LibHalChangeSet *cset;
+
+	if (! hfp_init (argc, argv))
+		goto out;
+
+	busstr = getenv ("HAL_PROP_USB_BUS_NUMBER");
+	if (! busstr)
+		goto out;
+	addrstr = getenv ("HAL_PROP_USB_PORT_NUMBER");
+	if (! addrstr)
+		goto out;
+	intfstr = getenv ("HAL_PROP_USB_INTERFACE_NUMBER");
+	if (! intfstr)
+		goto out;
+
+	bus = atoi (busstr);
+	addr = atoi (addrstr);
+	intf = atoi (intfstr);
+	if (intf != 0)
+		goto out;
+
+	unit = hfp_v4l_get_unit (bus, addr);
+	if (unit == -1)
+		goto out;
+	device_file = g_strdup_printf ("/dev/video%i", unit);
+	if (device_file == NULL)
+		goto out;
+
+	/* give a meaningful process title for ps(1) */
+	setproctitle("%s (bus: %i, addr: %i)", device_file, bus, addr);
+
+	cset = libhal_device_new_changeset (hfp_udi);
+
+	hfp_info ("Doing probe-video4linux for %s (udi=%s)", device_file, hfp_udi);
+
+	fd = open (device_file, O_RDONLY);
+	if (fd < 0) {
+		hfp_critical ("Cannot open %s: %s", device_file, strerror (errno));
+		goto out;
+	}
+
+	if (ioctl (fd, VIDIOC_QUERYCAP, &v2cap) == 0) {
+		libhal_changeset_set_property_string (cset,
+						      "video4linux.device", device_file);
+		libhal_changeset_set_property_string (cset,
+						      "info.category", "video4linux");
+		libhal_changeset_set_property_string (cset,
+		                                      "video4linux.version", "2");
+
+		libhal_changeset_set_property_string (cset,
+		                                      "info.product", (const char *)v2cap.card);
+
+		libhal_device_add_capability (hfp_ctx, hfp_udi, "video4linux", NULL);
+		if ((v2cap.capabilities & V4L2_CAP_VIDEO_CAPTURE) > 0) {
+			libhal_device_add_capability (hfp_ctx, hfp_udi, "video4linux.video_capture", NULL);
+		} if ((v2cap.capabilities & V4L2_CAP_VIDEO_OUTPUT) > 0) {
+			libhal_device_add_capability (hfp_ctx, hfp_udi, "video4linux.video_output", NULL);
+		} if ((v2cap.capabilities & V4L2_CAP_VIDEO_OVERLAY) > 0) {
+			libhal_device_add_capability (hfp_ctx, hfp_udi, "video4linux.video_overlay", NULL);
+		} if ((v2cap.capabilities & V4L2_CAP_AUDIO) > 0) {
+			libhal_device_add_capability (hfp_ctx, hfp_udi, "video4linux.audio", NULL);
+		} if ((v2cap.capabilities & V4L2_CAP_TUNER) > 0) {
+			libhal_device_add_capability (hfp_ctx, hfp_udi, "video4linux.tuner", NULL);
+		} if ((v2cap.capabilities & V4L2_CAP_RADIO) > 0) {
+			libhal_device_add_capability (hfp_ctx, hfp_udi, "video4linux.radio", NULL);
+		}
+	} else {
+		hfp_info (("ioctl VIDIOC_QUERYCAP failed"));
+
+		if (ioctl (fd, VIDIOCGCAP, &v1cap) == 0) {
+			libhal_changeset_set_property_string (cset,
+						      	      "video4linux.device", device_file);
+			libhal_changeset_set_property_string (cset,
+						       	      "info.category", "video4linux");
+			libhal_changeset_set_property_string (cset,
+			                                      "video4linux.version", "1");
+
+			libhal_changeset_set_property_string (cset,
+			                                      "info.product", v1cap.name);
+
+			libhal_device_add_capability (hfp_ctx, hfp_udi, "video4linux", NULL);
+			if ((v1cap.type & VID_TYPE_CAPTURE) > 0) {
+				libhal_device_add_capability (hfp_ctx, hfp_udi, "video4linux.video_capture", NULL);
+			} if ((v1cap.type & VID_TYPE_OVERLAY) > 0) {
+				libhal_device_add_capability (hfp_ctx, hfp_udi, "video4linux.video_overlay", NULL);
+			} if (v1cap.audios > 0) {
+				libhal_device_add_capability (hfp_ctx, hfp_udi, "video4linux.audio", NULL);
+			} if ((v1cap.type & VID_TYPE_TUNER) > 0) {
+				libhal_device_add_capability (hfp_ctx, hfp_udi, "video4linux.tuner", NULL);
+			}
+		} else {
+			hfp_info (("ioctl VIDIOCGCAP failed; not a v4l device"));
+		}
+	}
+
+	libhal_device_commit_changeset (hfp_ctx, cset, NULL);
+	libhal_device_free_changeset (cset);
+
+	close (fd);
+
+	ret = 0;
+
+out:
+	g_free (device_file);
+	if (fd >= 0)
+		close (fd);
+
+	return ret;
+}
+
