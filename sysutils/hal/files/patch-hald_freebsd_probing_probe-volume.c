--- hald/freebsd/probing/probe-volume.c.orig	2009-12-23 14:06:53.000000000 -0500
+++ hald/freebsd/probing/probe-volume.c	2009-12-23 14:07:01.000000000 -0500
@@ -574,6 +574,7 @@ main (int argc, char **argv)
 
 	  snprintf(ufsid, sizeof(ufsid), "%08x%08x", ufsdisk.d_fs.fs_id[0], ufsdisk.d_fs.fs_id[1]);
 	  libhal_device_set_property_string(hfp_ctx, hfp_udi, "volume.freebsd.ufsid", ufsid, &hfp_error);
+	  dbus_error_free(&hfp_error);
 	  ufs_devs = libhal_manager_find_device_string_match(hfp_ctx,
 			  				     "volume.freebsd.ufsid",
 							     ufsid,
@@ -582,16 +583,17 @@ main (int argc, char **argv)
 	  dbus_error_free(&hfp_error);
 	  for (i = 0; i < num_udis; i++)
             {
-              if (ufs_devs[i] != NULL)
+              if (ufs_devs[i] != NULL && strcmp(ufs_devs[i], hfp_udi))
                 {
                   gboolean mounted;
 
 		  mounted = libhal_device_get_property_bool(hfp_ctx, ufs_devs[i], "volume.is_mounted", &hfp_error);
-		  dbus_error_free(&hfp_error);
+	          dbus_error_free(&hfp_error);
 		  if (mounted)
-		    {
+	            {
                       libhal_device_set_property_bool(hfp_ctx, hfp_udi, "volume.ignore", TRUE, &hfp_error);
 		      dbus_error_free(&hfp_error);
+		      break;
 		    }
 		}
 	    }
