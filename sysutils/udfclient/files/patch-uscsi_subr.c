--- uscsi_subr.c.orig	2011-11-15 19:51:44.387439246 +0200
+++ uscsi_subr.c	2011-11-27 16:41:07.706327140 +0200
@@ -412,6 +412,7 @@ uscsi_command(int flags, struct uscsi_de
 	struct scsi_sense_data *cam_sense_data;
 	union ccb ccb;
 	uint32_t cam_sense;
+	u_int sense_len;
 	uint8_t *keypos;
 	int camflags;
 
@@ -468,17 +469,33 @@ uscsi_command(int flags, struct uscsi_de
 
 	/* print sense info */
 	cam_sense_data = &ccb.csio.sense_data;
+	sense_len = ccb.csio.sense_len - ccb.csio.sense_resid;
 	if (uscsi_sense) {
+#if __FreeBSD_version > 900043
+		int error_code, sense_key;
+		uint8_t sks[3];
+
+		scsi_extract_sense_len(cam_sense_data, sense_len,
+		    &error_code, &sense_key,
+		    &uscsi_sense->asc, &uscsi_sense->ascq, /*show_errors*/ 0);
+
+		if ((scsi_get_sks(cam_sense_data, sense_len, sks) == 0)) {
+			uscsi_sense->skey_valid = 1;
+			uscsi_sense->sense_key  = (sks[1] << 8) | sks[2];
+		} else
+			uscsi_sense->skey_valid = 0;
+#else
 		uscsi_sense->asc  = cam_sense_data->add_sense_code;
 		uscsi_sense->ascq = cam_sense_data->add_sense_code_qual;
 		keypos  = cam_sense_data->sense_key_spec;
 		uscsi_sense->skey_valid =  keypos[0] & 128;
 		uscsi_sense->sense_key  = (keypos[1] << 8) | (keypos[2]);
+#endif
 	}
 
 	uscsi_print_sense((char *) disc->dev_name,
 		cmd, cmdlen,
-		(uint8_t *) cam_sense_data, 8 + cam_sense_data->extra_len, 1);
+		(uint8_t *) cam_sense_data, sense_len, 1);
 
 	return EFAULT;
 }
