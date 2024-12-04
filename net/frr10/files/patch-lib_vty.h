--- lib/vty.h.orig	2024-11-12 16:20:46 UTC
+++ lib/vty.h
@@ -237,6 +237,9 @@ struct vty {
 	bool mgmt_locked_candidate_ds;
 	bool mgmt_locked_running_ds;
 	uint64_t vty_buf_size_accumulated;
+
+	int buf_size_set;
+	uint64_t buf_size_intermediate;
 };
 
 static inline void vty_push_context(struct vty *vty, int node, uint64_t id)
