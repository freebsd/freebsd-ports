--- sys/fs/pefs/pefs_vnops.c.orig	2018-11-16 12:26:20 UTC
+++ sys/fs/pefs/pefs_vnops.c
@@ -1920,7 +1920,7 @@ pefs_symlink(struct vop_symlink_args *ap)
 	struct pefs_node *dpn;
 	struct pefs_enccn enccn;
 	struct pefs_chunk pc;
-	char *target = ap->a_target;
+	const char *target = ap->a_target;
 	char *enc_target, *penc_target;
 	size_t penc_target_len;
 	size_t target_len;
