--- lib/login.c.orig	2019-07-13 22:04:44 UTC
+++ lib/login.c
@@ -1242,11 +1242,11 @@ iscsi_process_login_reply(struct iscsi_context *iscsi,
 
         /* iSER specific keys */
         if (!strncmp(ptr, "InitiatorRecvDataSegmentLength=", 31)) {
-			iscsi->initiator_max_recv_data_segment_length = MIN(strtol(ptr + 31, NULL, 10),
+			iscsi->initiator_max_recv_data_segment_length = MIN(strtoul(ptr + 31, NULL, 10),
                                                              iscsi->initiator_max_recv_data_segment_length);
         }
         if (!strncmp(ptr, "TargetRecvDataSegmentLength=", 28)) {
-			iscsi->target_max_recv_data_segment_length = MIN(strtol(ptr + 28, NULL, 10),
+			iscsi->target_max_recv_data_segment_length = MIN(strtoul(ptr + 28, NULL, 10),
                                                              iscsi->target_max_recv_data_segment_length);
         }
 
