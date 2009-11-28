--- hald/freebsd/probing/probe-volume.c.orig	2008-08-10 09:50:10.000000000 -0400
+++ hald/freebsd/probing/probe-volume.c	2009-09-26 03:54:16.000000000 -0400
@@ -36,7 +36,12 @@
 #include <sys/disk.h>
 #include <sys/cdio.h>
 #include <sys/param.h>
+#include <sys/mount.h>
 #include <sys/types.h>
+#include <ufs/ufs/ufsmount.h>
+#include <ufs/ufs/dinode.h>
+#include <ufs/ffs/fs.h>
+#include <libufs.h>
 #include <isofs/cd9660/iso.h>
 #include <glib.h>
 #include <libvolume_id.h>
@@ -502,7 +507,8 @@ main (int argc, char **argv)
 	  hfp_cdrom_free(cdrom);
 	}
 
-      if (has_data)
+      if (has_data && vid && (! strcmp(vid->type, "iso9660") ||
+          ! strcmp(vid->type, "udf")))
         hf_probe_volume_advanced_disc_detect(fd);
     }
   else
@@ -555,6 +561,48 @@ main (int argc, char **argv)
 
   libhal_device_set_property_bool(hfp_ctx, hfp_udi, "volume.ignore", has_children || is_swap, &hfp_error);
 
+  if (vid && ! strcmp (vid->type, "ufs"))
+    {
+      struct uufsd ufsdisk;
+
+      if (ufs_disk_fillout(&ufsdisk, device_file) == 0)
+        {
+	  char ufsid[64];
+	  char **ufs_devs = NULL;
+	  int num_udis;
+	  int i;
+
+	  snprintf(ufsid, sizeof(ufsid), "%08x%08x", ufsdisk.d_fs.fs_id[0], ufsdisk.d_fs.fs_id[1]);
+	  libhal_device_set_property_string(hfp_ctx, hfp_udi, "volume.freebsd.ufsid", ufsid, &hfp_error);
+	  dbus_error_free(&hfp_error);
+	  ufs_devs = libhal_manager_find_device_string_match(hfp_ctx,
+			  				     "volume.freebsd.ufsid",
+							     ufsid,
+							     &num_udis,
+							     &hfp_error);
+	  dbus_error_free(&hfp_error);
+	  for (i = 0; i < num_udis; i++)
+            {
+              if (ufs_devs[i] != NULL && strcmp(ufs_devs[i], hfp_udi))
+                {
+                  gboolean mounted;
+
+		  mounted = libhal_device_get_property_bool(hfp_ctx, ufs_devs[i], "volume.is_mounted", &hfp_error);
+	          dbus_error_free(&hfp_error);
+		  if (mounted)
+	            {
+                      libhal_device_set_property_bool(hfp_ctx, hfp_udi, "volume.ignore", TRUE, &hfp_error);
+		      dbus_error_free(&hfp_error);
+		      break;
+		    }
+		}
+	    }
+	  if (ufs_devs)
+	    libhal_free_string_array(ufs_devs);
+	  ufs_disk_close(&ufsdisk);
+	}
+    }
+
   if (has_children)
     usage = "partitiontable";
   else if (is_swap)
