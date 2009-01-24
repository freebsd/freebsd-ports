--- hald/freebsd/addons/addon-mouse.c.orig	2009-01-24 02:12:21.000000000 -0500
+++ hald/freebsd/addons/addon-mouse.c	2009-01-24 02:14:11.000000000 -0500
@@ -0,0 +1,319 @@
+/***************************************************************************
+ * CVSID: $Id$
+ *
+ * addon-mouse.c : poll mice to disable moused(8) owned devices
+ *
+ * Copyright (C) 2008 Joe Marcus Clarke
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
+#if __FreeBSD_version >= 800058
+#include <sys/types.h>
+#include <sys/user.h>
+#include <sys/sysctl.h>
+#include <libutil.h>
+#endif
+#include <string.h>
+#include <stdlib.h>
+#include <assert.h>
+#include <unistd.h>
+#include <glib.h>
+
+#include "libhal/libhal.h"
+
+#include "../libprobe/hfp.h"
+
+#if __FreeBSD_version < 800058
+#define CMD "/usr/bin/fstat %s"
+#endif
+
+#define MOUSE_DRIVER "mouse"
+#define MOUSED_DEVICE "/dev/sysmouse"
+#define MOUSED_PROC_NAME "moused"
+
+static struct
+{
+  const struct timespec        update_interval;
+  char                        *device_file;
+  struct timespec              next_update;
+} addon = { { 2, 0 } };
+
+#if __FreeBSD_version >= 800058
+static struct kinfo_proc *
+hfp_kinfo_getproc (int *cntp)
+{
+  int mib[3];
+  int error;
+  int cnt;
+  size_t len;
+  char *buf, *bp, *eb;
+  struct kinfo_proc *kip, *kp, *ki;
+
+  *cntp = 0;
+
+  len = 0;
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC;
+  mib[2] = KERN_PROC_PROC;
+
+  error = sysctl(mib, 3, NULL, &len, NULL, 0);
+  if (error)
+    return NULL;
+
+  len = len * 4 / 3;
+  buf = (char *) g_malloc(len);
+  if (buf == NULL)
+    return NULL;
+
+  error = sysctl(mib, 3, buf, &len, NULL, 0);
+  if (error)
+    {
+      g_free(buf);
+      return NULL;
+    }
+
+  cnt = 0;
+  bp = buf;
+  eb = buf + len;
+  while (bp < eb)
+    {
+      ki =  (struct kinfo_proc *) (uintptr_t) bp;
+      bp += ki->ki_structsize;
+      cnt++;
+    }
+
+  kip = calloc(cnt, sizeof (*kip));
+  if (kip == NULL)
+    {
+      g_free(buf);
+      return NULL;
+    }
+
+  bp = buf;
+  eb = buf + len;
+  kp = kip;
+  while (bp < eb)
+    {
+      ki = (struct kinfo_proc *) (uintptr_t) bp;
+      memcpy(kp, ki, ki->ki_structsize);
+      bp += ki->ki_structsize;
+      kp->ki_structsize = sizeof(*kp);
+      kp++;
+    }
+
+  g_free(buf);
+  *cntp = cnt;
+  return kip;
+}
+
+static gboolean
+device_opened_by_proc (const char *device, const char *proc)
+{
+  struct kinfo_proc *kip, *pfreep;
+  int cnt, i;
+
+  pfreep = hfp_kinfo_getproc(&cnt);
+  if (pfreep == NULL)
+    return FALSE;
+
+  for (i = 0; i < cnt; i++)
+    {
+      kip = &pfreep[i];
+
+      if (! strcmp(kip->ki_comm, proc))
+        {
+          struct kinfo_file *kif, *ffreep;
+          int fcnt, j;
+
+          ffreep = kinfo_getfile(kip->ki_pid, &fcnt);
+          if (ffreep == NULL)
+                  continue;
+          for (j = 0; j < fcnt; j++)
+            {
+              kif = &ffreep[j];
+
+              if (kif->kf_type == KF_TYPE_VNODE &&
+                  ! strcmp(kif->kf_path, device))
+                {
+                  g_free(ffreep);
+                  g_free(pfreep);
+                  return TRUE;
+                }
+            }
+          g_free(ffreep);
+        }
+    }
+  g_free(pfreep);
+
+  return FALSE;
+}
+#else
+static gboolean
+device_opened_by_proc (const char *device, const char *proc)
+{
+  char **lines;
+  char *output = NULL;
+  char *cmd;
+  int i;
+  gboolean found = FALSE;
+
+  cmd = g_strdup_printf(CMD, device);
+
+  if (! g_spawn_command_line_sync (cmd, &output, NULL, NULL, NULL))
+    {
+      g_free(cmd);
+      goto done;
+    }
+  g_free(cmd);
+
+  if (! output || strlen(output) == 0)
+    goto done;
+
+  lines = g_strsplit(output, "\n", 0);
+  if (g_strv_length(lines) < 2)
+    {
+      g_strfreev(lines);
+      goto done;
+    }
+
+  for (i = 1; lines[i]; i++)
+    {
+      char **fields;
+      guint len;
+      guint j;
+
+      fields = g_strsplit_set(lines[i], " ", 0);
+      len = g_strv_length(fields);
+      if (len < 2)
+        {
+          g_strfreev(fields);
+          continue;
+        }
+      for (j = 1; j < len && fields[j] && *fields[j] == '\0'; j++)
+        ;
+      if (j < len && fields[j] && ! strcmp(fields[j], proc))
+        {
+          found = TRUE;
+          g_strfreev(fields);
+          break;
+        }
+      g_strfreev(fields);
+    }
+
+  g_strfreev(lines);
+
+done:
+  g_free(output);
+
+  return found;
+}
+#endif
+
+static const char *
+get_mouse_device (const char *device)
+{
+  if (device_opened_by_proc(device, MOUSED_PROC_NAME))
+    return MOUSED_DEVICE;
+
+  return device;
+}
+
+static void
+poll_for_moused (void)
+{
+  char *old_device;
+  const char *device;
+  gboolean found;
+
+  old_device = libhal_device_get_property_string(hfp_ctx, hfp_udi, "input.device", &hfp_error);
+  dbus_error_free(&hfp_error);
+
+  device = get_mouse_device(addon.device_file);
+  if (strcmp(old_device, device))
+    {
+      libhal_device_remove_property(hfp_ctx, hfp_udi, "input.device", &hfp_error);
+      dbus_error_free(&hfp_error);
+      libhal_device_set_property_string(hfp_ctx, hfp_udi, "input.device", device, &hfp_error);
+      dbus_error_free(&hfp_error);
+    }
+  g_free(old_device);
+
+  libhal_device_set_property_string(hfp_ctx, hfp_udi, "input.x11_driver", MOUSE_DRIVER, &hfp_error);
+  dbus_error_free(&hfp_error);
+}
+
+int
+main (int argc, char **argv)
+{
+  DBusConnection *connection;
+
+  if (! hfp_init(argc, argv))
+    goto end;
+
+  addon.device_file = getenv("HAL_PROP_FREEBSD_DEVICE_FILE");
+  if (! addon.device_file)
+    goto end;
+
+  setproctitle("%s", addon.device_file);
+
+  if (! libhal_device_addon_is_ready(hfp_ctx, hfp_udi, &hfp_error))
+    goto end;
+  dbus_error_free(&hfp_error);
+
+  connection = libhal_ctx_get_dbus_connection(hfp_ctx);
+  assert(connection != NULL);
+
+  while (TRUE)
+    {
+      /* process dbus traffic until update interval has elapsed */
+      while (TRUE)
+        {
+          struct timespec now;
+
+          hfp_clock_gettime(&now);
+          if (hfp_timespeccmp(&now, &addon.next_update, <))
+            {
+              struct timespec timeout;
+
+              timeout = addon.next_update;
+              hfp_timespecsub(&timeout, &now);
+
+              if (timeout.tv_sec < 0) /* current time went backwards */
+                timeout = addon.update_interval;
+
+              dbus_connection_read_write_dispatch(connection, timeout.tv_sec * 1000 + timeout.tv_nsec / 1000000);
+              if (! dbus_connection_get_is_connected(connection))
+                goto end;
+            }
+          else
+            break;
+        }
+
+      poll_for_moused();
+
+      hfp_clock_gettime(&addon.next_update);
+      hfp_timespecadd(&addon.next_update, &addon.update_interval);
+    }
+
+ end:
+  return 0;
+}
