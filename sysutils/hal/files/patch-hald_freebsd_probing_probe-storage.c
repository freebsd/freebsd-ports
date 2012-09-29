--- hald/freebsd/probing/probe-storage.c.orig	2009-08-24 14:42:29.000000000 +0200
+++ hald/freebsd/probing/probe-storage.c	2012-09-27 12:03:02.000000000 +0200
@@ -236,7 +236,27 @@
 
       hfp_cdrom_free(cdrom);
     }
-  else if (! has_children) /* by definition, if it has children it has no fs */
+  else
+    {
+      int fd;
+      off_t size;
+
+      fd = open(device_file, O_RDONLY | O_NONBLOCK);
+      if (fd > -1)
+	{
+	  libhal_device_set_property_bool(hfp_ctx, hfp_udi, "storage.removable.media_available", TRUE, &hfp_error);
+	  if (ioctl (fd, DIOCGMEDIASIZE, &size) == 0)
+	    {
+	      libhal_device_set_property_uint64(hfp_ctx, hfp_udi, "storage.removable.media_size", size, &hfp_error);
+	    }
+	  close(fd);
+	}
+      else
+	{
+	  libhal_device_set_property_bool(hfp_ctx, hfp_udi, "storage.removable.media_available", FALSE, &hfp_error);
+	}
+
+      if (! has_children) /* by definition, if it has children it has no fs */
     {
       struct volume_id *vid;
 
@@ -249,6 +269,7 @@
 
       volume_id_close(vid);
     }
+    }
 
  end:
   return ret;
