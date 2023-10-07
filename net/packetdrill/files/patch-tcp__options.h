--- tcp_options.h.orig	2023-10-07 04:31:15 UTC
+++ tcp_options.h
@@ -166,7 +166,7 @@ struct tcp_option {
 		struct {
 			u8 data[MAX_TCP_OPTION_DATA_BYTES];
 		} generic;
-	};
+	} __packed;
 	u32 flags;  /* meta information, not going on the wire */
 } __packed;
 
