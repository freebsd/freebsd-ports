--- ike_quick_mode.c	2004/08/14 13:29:50	1.86
+++ ike_quick_mode.c	2004/09/17 13:53:08	1.87
@@ -1739,8 +1739,11 @@
 			    "strdup (\"%s\") failed", name);
 			goto cleanup;
 		}
-	} else if (ignore_policy || strncmp("yes", conf_get_str("General",
-	    "Use-Keynote"), 3)) {
+	} else if (
+#ifdef USE_POLICY
+	    ignore_policy ||
+#endif
+	    strncmp("yes", conf_get_str("General", "Use-Keynote"), 3)) {
 		log_print("responder_recv_HASH_SA_NONCE: peer proposed "
 		    "invalid phase 2 IDs: %s",
 		        (exchange->doi->decode_ids("initiator id %s, responder"
