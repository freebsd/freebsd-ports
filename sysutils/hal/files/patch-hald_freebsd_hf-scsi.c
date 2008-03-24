--- hald/freebsd/hf-scsi.c.orig	2008-03-18 15:58:59.000000000 -0400
+++ hald/freebsd/hf-scsi.c	2008-03-18 15:57:36.000000000 -0400
@@ -409,8 +409,8 @@ hf_scsi_handle_pending_device (struct de
 		   */
 		  hf_block_device_complete(block_device, block_device, FALSE);
 
-		  hf_storage_device_probe(block_device, FALSE);
 		  hf_device_add(block_device);
+		  hf_storage_device_probe(block_device, FALSE);
 		}
 	    }
 	}
