--- logprint/log_misc.c.orig	Fri Jul  7 12:34:53 2006
+++ logprint/log_misc.c	Fri Jul  7 12:35:26 2006
@@ -1530,7 +1530,7 @@
 		in_f->ilf_dsize = in_f32->ilf_dsize;
 		in_f->ilf_ino = in_f32->ilf_ino;
 		/* copy biggest */
-		memcpy(in_f->ilf_u.ilfu_uuid, in_f32->ilf_u.ilfu_uuid, sizeof(uuid_t));
+		memcpy(&in_f->ilf_u.ilfu_uuid, &in_f32->ilf_u.ilfu_uuid, sizeof(uuid_t));
 		in_f->ilf_blkno = in_f32->ilf_blkno;
 		in_f->ilf_len = in_f32->ilf_len;
 		in_f->ilf_boffset = in_f32->ilf_boffset;
@@ -1546,7 +1546,7 @@
 		in_f->ilf_dsize = in_f64->ilf_dsize;
 		in_f->ilf_ino = in_f64->ilf_ino;
 		/* copy biggest */
-		memcpy(in_f->ilf_u.ilfu_uuid, in_f64->ilf_u.ilfu_uuid, sizeof(uuid_t));
+		memcpy(&in_f->ilf_u.ilfu_uuid, &in_f64->ilf_u.ilfu_uuid, sizeof(uuid_t));
 		in_f->ilf_blkno = in_f64->ilf_blkno;
 		in_f->ilf_len = in_f64->ilf_len;
 		in_f->ilf_boffset = in_f64->ilf_boffset;
