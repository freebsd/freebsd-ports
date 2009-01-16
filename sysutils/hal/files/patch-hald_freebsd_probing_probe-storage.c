--- hald/freebsd/probing/probe-storage.c.orig	2009-01-12 16:07:59.000000000 -0500
+++ hald/freebsd/probing/probe-storage.c	2009-01-12 16:20:20.000000000 -0500
@@ -31,6 +31,8 @@
 #include <unistd.h>
 #include <errno.h>
 #include <sys/types.h>
+#include <sys/ioctl.h>
+#include <sys/disk.h>
 #include <netinet/in.h>
 #include <glib.h>
 #include <libvolume_id.h>
@@ -211,7 +213,26 @@ main (int argc, char **argv)
 	goto end;
 
       if (hfp_cdrom_test_unit_ready(cdrom))
-	ret = 2;		/* has media */
+        {
+	  int fd;
+	  off_t size;
+
+          libhal_device_set_property_bool(hfp_ctx, hfp_udi, "storage.removable.media_available", TRUE, &hfp_error);
+	  fd = open(device_file, O_RDONLY | O_NONBLOCK);
+	  if (fd > -1)
+            {
+              if (ioctl (fd, DIOCGMEDIASIZE, &size) == 0)
+                {
+                  libhal_device_set_property_uint64(hfp_ctx, hfp_udi, "storage.removable.media_size", size, &hfp_error);
+		}
+	      close(fd);
+	    }
+	  ret = 2;		/* has media */
+	}
+      else
+        {
+          libhal_device_set_property_bool(hfp_ctx, hfp_udi, "storage.removable.media_available", FALSE, &hfp_error);
+	}
 
       hfp_cdrom_free(cdrom);
     }
