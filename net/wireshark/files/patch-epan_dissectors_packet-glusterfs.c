--- epan/dissectors/packet-glusterfs.c.orig	2013-04-22 14:05:16.000000000 -0400
+++ epan/dissectors/packet-glusterfs.c	2013-10-12 13:18:58.000000000 -0400
@@ -2002,15 +2002,15 @@ static value_string_ext glusterfs3_1_fop
 
 /* dir-entry types */
 static const value_string glusterfs_entry_type_names[] = {
-	{ DT_UNKNOWN, "DT_UNKNOWN" },
-	{ DT_FIFO,    "DT_FIFO" },
-	{ DT_CHR,     "DT_CHR" },
-	{ DT_DIR,     "DT_DIR" },
-	{ DT_BLK,     "DT_BLK" },
-	{ DT_REG,     "DT_REG" },
-	{ DT_LNK,     "DT_LNK" },
-	{ DT_SOCK,    "DT_SOCK" },
-	{ DT_WHT,     "DT_WHT" },
+	{ GLFS_DT_UNKNOWN, "DT_UNKNOWN" },
+	{ GLFS_DT_FIFO,    "DT_FIFO" },
+	{ GLFS_DT_CHR,     "DT_CHR" },
+	{ GLFS_DT_DIR,     "DT_DIR" },
+	{ GLFS_DT_BLK,     "DT_BLK" },
+	{ GLFS_DT_REG,     "DT_REG" },
+	{ GLFS_DT_LNK,     "DT_LNK" },
+	{ GLFS_DT_SOCK,    "DT_SOCK" },
+	{ GLFS_DT_WHT,     "DT_WHT" },
 	{ 0, NULL }
 };
 static value_string_ext glusterfs_entry_type_names_ext = VALUE_STRING_EXT_INIT(glusterfs_entry_type_names);
