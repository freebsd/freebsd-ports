--- hald/freebsd/probing/probe-volume.c.orig	2008-04-07 00:41:22.000000000 -0400
+++ hald/freebsd/probing/probe-volume.c	2008-04-07 00:43:32.000000000 -0400
@@ -502,7 +502,8 @@ main (int argc, char **argv)
 	  hfp_cdrom_free(cdrom);
 	}
 
-      if (has_data)
+      if (has_data && vid && (! strcmp(vid->type, "iso9660") ||
+          ! strcmp(vid->type, "udf")))
         hf_probe_volume_advanced_disc_detect(fd);
     }
   else
