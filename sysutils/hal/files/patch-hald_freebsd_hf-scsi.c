--- hald/freebsd/hf-scsi.c.orig	2009-08-18 16:19:02.000000000 -0400
+++ hald/freebsd/hf-scsi.c	2009-08-18 16:19:24.000000000 -0400
@@ -549,7 +549,7 @@ hf_scsi_probe (void)
 		break;		/* only use the first peripheral */
 
 	      match = &ccb.cdm.matches[i].result.periph_result;
-	      if ((int) match->path_id == -1 || ! strcmp(match->periph_name, "pass"))
+	      if ((int) match->path_id == -1 || ! strcmp(match->periph_name, "pass") || ! strcmp(match->periph_name, "probe"))
 		break;
 
 	      pending_devname = g_strdup_printf("%s%i", match->periph_name, match->unit_number);
