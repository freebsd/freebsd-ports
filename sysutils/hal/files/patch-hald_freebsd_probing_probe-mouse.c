--- hald/freebsd/probing/probe-mouse.c.orig	2009-01-25 16:54:29.000000000 -0500
+++ hald/freebsd/probing/probe-mouse.c	2009-01-25 18:40:04.000000000 -0500
@@ -0,0 +1,301 @@
+/***************************************************************************
+ * CVSID: $Id$
+ *
+ * probe-hiddev.c : Mouse prober
+ *
+ * Copyright (C) 2008 Joe Marcus Clarke <marcus@FreeBSD.org>
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
+#include <unistd.h>
+#include <stdlib.h>
+#include <string.h>
+#include <fcntl.h>
+#include <glib.h>
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
+#define XORG_PROC_NAME "Xorg"
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
+  if (! g_spawn_command_line_sync(cmd, &output, NULL, NULL, NULL))
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
+      if (len < 3)
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
+static void
+probe_mouse (const char *device_file)
+{
+  gboolean found;
+  char *driver;
+
+  driver = libhal_device_get_property_string(hfp_ctx, hfp_udi,
+                                             "input.x11_driver", &hfp_error);
+  dbus_error_free(&hfp_error);
+
+  found = device_opened_by_proc(device_file, XORG_PROC_NAME);
+  if (found)
+    {
+      if (driver)
+        {
+          libhal_device_remove_property(hfp_ctx, hfp_udi, "input.x11_driver",
+                                        &hfp_error);
+	  dbus_error_free(&hfp_error);
+	  g_free(driver);
+	}
+      return;
+    }
+
+  found = device_opened_by_proc(device_file, MOUSED_PROC_NAME);
+  if (found)
+    {
+      libhal_device_set_property_string(hfp_ctx, hfp_udi, "input.device",
+                                        MOUSED_DEVICE, &hfp_error);
+      dbus_error_free(&hfp_error);
+      found = device_opened_by_proc(MOUSED_DEVICE, XORG_PROC_NAME);
+      if (! found)
+        {
+          libhal_device_set_property_string(hfp_ctx, hfp_udi,
+			                    "input.x11_driver",
+                                            MOUSE_DRIVER, &hfp_error);
+	  dbus_error_free(&hfp_error);
+	}
+      else if (driver)
+        {
+          libhal_device_remove_property(hfp_ctx, hfp_udi, "input.x11_driver",
+                                        &hfp_error);
+	  dbus_error_free(&hfp_error);
+	}
+    }
+  else
+    {
+      libhal_device_set_property_string(hfp_ctx, hfp_udi, "input.device",
+                                        device_file, &hfp_error);
+      dbus_error_free(&hfp_error);
+      libhal_device_set_property_string(hfp_ctx, hfp_udi, "input.x11_driver",
+                                        MOUSE_DRIVER, &hfp_error);
+      dbus_error_free(&hfp_error);
+    }
+
+  g_free(driver);
+}
+
+int
+main (int argc, char **argv)
+{
+  char *device_file;
+
+  if (! hfp_init(argc, argv))
+    goto end;
+
+  device_file = getenv("HAL_PROP_FREEBSD_DEVICE_FILE");
+  if (! device_file)
+    goto end;
+
+  /* give a meaningful process title for ps(1) */
+  setproctitle("%s", device_file);
+
+  /* Sleep for a second to give moused a chance to connect. */
+  sleep(1);
+  probe_mouse(device_file);
+
+ end:
+  return 0;
+}
