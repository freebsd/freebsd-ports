--- epan/dissectors/packet-gluster.h.orig	2013-04-22 14:05:17.000000000 -0400
+++ epan/dissectors/packet-gluster.h	2013-10-12 13:14:25.000000000 -0400
@@ -356,18 +356,17 @@ enum gf_fop_procnum {
 
 /* dir-entry types from libglusterfs/src/compat.h */
 enum gluster_entry_types {
-	DT_UNKNOWN = 0,
-	DT_FIFO = 1,
-	DT_CHR = 2,
-	DT_DIR = 4,
-	DT_BLK = 6,
-	DT_REG = 8,
-	DT_LNK = 10,
-	DT_SOCK = 12,
-	DT_WHT = 14
+	GLFS_DT_UNKNOWN = 0,
+	GLFS_DT_FIFO = 1,
+	GLFS_DT_CHR = 2,
+	GLFS_DT_DIR = 4,
+	GLFS_DT_BLK = 6,
+	GLFS_DT_REG = 8,
+	GLFS_DT_LNK = 10,
+	GLFS_DT_SOCK = 12,
+	GLFS_DT_WHT = 14
 };
 
-
 /* LOCKING operators come from libglusterfs/src/glusterfs.h */
 
 /* based on original enum glusterfs_lk_cmds_t */
