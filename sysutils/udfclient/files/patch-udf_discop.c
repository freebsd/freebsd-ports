diff -u -r udf_discop.c.orig udf_discop.c
--- udf_discop.c.orig	Thu Jan 27 16:45:23 2005
+++ udf_discop.c	Fri Feb  4 22:23:50 2005
@@ -210,7 +210,7 @@
 	/* Set CD/DVD speed on 'optimal' for it doesnt seem to do it automatically */
 	bzero(cmd, SCSI_CMD_LEN);
 	cmd[ 0] = 0xBB;				/* Set CD speed */
-	cmd[ 1] = 1;				/* select CAV (1) or CLV (0) recording */
+	cmd[ 1] = 0;				/* select pure CAV (1) or CLV and non-pure CAV (0) recording */
 	cmd[ 2] = 0xff;
 	cmd[ 3] = 0xff;				/* max read performance speed */
 	cmd[ 4] = 0xff;
