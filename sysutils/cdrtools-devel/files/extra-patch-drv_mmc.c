--- cdrecord/drv_mmc.c.orig	Thu Oct  9 01:10:41 2003
+++ cdrecord/drv_mmc.c	Thu Oct  9 01:31:28 2003
@@ -224,13 +224,13 @@
          scsi_unload,
          read_buff_cap,
          cmd_dummy,                              /* recovery_needed      */
-         (int(*)__PR((SCSI *, int)))cmd_dummy,   /* recover              */
+         (int(*)__PR((SCSI *, cdr_t *, int)))cmd_dummy, /* recover	*/
          speed_select_mdvd,
          select_secsize,
          next_wr_addr_mdvd,
          (int(*)__PR((SCSI *, Ulong)))cmd_ill,   /* reserve_track        */
          scsi_cdr_write,
-         (int(*)__PR((SCSI *scgp, int, track_t *)))cmd_dummy, /* gen_cue */
+         (int(*)__PR((track_t *, void *, BOOL)))cmd_dummy, /* gen_cue */
 	 (int(*)__PR((SCSI *scgp, cdr_t *, track_t *)))cmd_dummy, /* send_cue */
  	 write_leadin_mmc,
          open_track_mdvd,
@@ -702,8 +702,7 @@
 #endif
 	}
 	if (is_dvd) {
-	        errmsgno(EX_BAD, 
-                "Found DVD media: using cdr_mdvd.\n");  
+		printf("Found DVD media: using cdr_mdvd.\n");  
                 dp = &cdr_mdvd; 
 	}
 	return (dp);
@@ -1083,7 +1082,7 @@
 	return (0);
 }
 
-LOCAL int
+EXPORT int
 check_writemodes_mdvd(scgp, dp)
 	SCSI	*scgp;
 	cdr_t	*dp;
