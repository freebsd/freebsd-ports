--- hald/freebsd/hf-volume.c.orig	2008-05-07 19:24:03.000000000 -0400
+++ hald/freebsd/hf-volume.c	2008-10-26 15:17:09.000000000 -0400
@@ -45,6 +45,7 @@
 #include "hf-util.h"
 
 #define PROBE_VOLUME_TIMEOUT		(HAL_HELPER_TIMEOUT * 6)
+#define HF_VOLUME_FUSE_DB		"/tmp/.fuse-mnts"
 
 static void
 hf_volume_get_mounts (struct statfs **mounts, int *n_mounts)
@@ -60,6 +61,55 @@ hf_volume_get_mounts (struct statfs **mo
     }
 }
 
+static char *
+hf_volume_resolve_fuse (const char *special)
+{
+  gchar *contents;
+  gchar **lines;
+  gsize len;
+  int i;
+
+  g_return_val_if_fail(special != NULL, NULL);
+
+  if (! g_file_get_contents(HF_VOLUME_FUSE_DB, &contents, &len, NULL))
+    return g_strdup(special);
+
+  lines = g_strsplit(contents, "\n", 0);
+  g_free(contents);
+
+  for (i = 0; lines && lines[i]; i++)
+    {
+      gchar **fields;
+
+      fields = g_strsplit(lines[i], "=", 2);
+      if (fields && g_strv_length(fields) == 2)
+        {
+          if (strcmp(fields[0], special) == 0)
+	    {
+	      g_strfreev(fields);
+	      g_strfreev(lines);
+	      return g_strdup(fields[1]);
+	    }
+	}
+      g_strfreev(fields);
+    }
+
+    g_strfreev(lines);
+
+    return g_strdup(special);
+}
+
+static char *
+hf_volume_resolve_special (const char *special)
+{
+  g_return_val_if_fail(special != NULL, NULL);
+
+  if (strstr(special, "fuse"))
+    return hf_volume_resolve_fuse(special);
+
+  return g_strdup(special);
+}
+
 static const struct statfs *
 hf_volume_mounts_find (const struct statfs *mounts,
 		       int n_mounts,
@@ -71,8 +121,18 @@ hf_volume_mounts_find (const struct stat
   g_return_val_if_fail(special != NULL, NULL);
 
   for (i = 0; i < n_mounts; i++)
-    if (! strcmp(mounts[i].f_mntfromname, special))
-      return &mounts[i];
+    {
+      char *resolved;
+
+      resolved = hf_volume_resolve_special(mounts[i].f_mntfromname);
+      if (! strcmp(resolved, special))
+        {
+	  g_free(resolved);
+          return &mounts[i];
+	}
+
+      g_free(resolved);
+    }
 
   return NULL;
 }
@@ -92,7 +152,13 @@ hf_volume_device_update_mount_properties
 
       special = hal_device_property_get_string(device, "block.device");
       if (special)
-	mount = hf_volume_mounts_find(mounts, n_mounts, special);
+	{
+	  mount = hf_volume_mounts_find(mounts, n_mounts, special);
+          if (mount && strcmp(special, mount->f_mntfromname))
+            hal_device_property_set_string(device, "volume.freebsd.real_mounted_device", mount->f_mntfromname);
+	  else
+	    hal_device_property_remove(device, "volume.freebsd.real_mounted_device");
+	}
     }
 
   hal_device_property_set_bool(device, "volume.is_mounted", mount != NULL);
