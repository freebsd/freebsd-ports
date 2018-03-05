--- src/libserver/milter.c.orig	2017-10-22 16:16:54 UTC
+++ src/libserver/milter.c
@@ -99,6 +99,8 @@ rspamd_milter_session_reset (struct rspa
 	guint i;
 
 	if (how & RSPAMD_MILTER_RESET_IO) {
+		msg_debug_milter ("cleanup IO on abort");
+
 		DL_FOREACH_SAFE (priv->out_chain, obuf, obuf_tmp) {
 			rspamd_milter_obuf_free (obuf);
 		}
@@ -111,8 +113,11 @@ rspamd_milter_session_reset (struct rspa
 	}
 
 	if (how & RSPAMD_MILTER_RESET_COMMON) {
+		msg_debug_milter ("cleanup common data on abort");
+
 		if (session->message) {
 			session->message->len = 0;
+			msg_debug_milter ("cleanup message on abort");
 		}
 
 		if (session->rcpts) {
@@ -120,30 +125,38 @@ rspamd_milter_session_reset (struct rspa
 				rspamd_email_address_unref (cur);
 			}
 
+			msg_debug_milter ("cleanup %d recipients on abort",
+					(gint)session->rcpts->len);
+
 			g_ptr_array_free (session->rcpts, TRUE);
 			session->rcpts = NULL;
 		}
 
 		if (session->from) {
+			msg_debug_milter ("cleanup from");
 			rspamd_email_address_unref (session->from);
 			session->from = NULL;
 		}
 
 		if (session->helo) {
+			msg_debug_milter ("cleanup helo");
 			session->helo->len = 0;
 		}
 
 		if (session->hostname) {
+			msg_debug_milter ("cleanup hostname");
 			session->hostname->len = 0;
 		}
 
 		if (priv->headers) {
+			msg_debug_milter ("cleanup headers");
 			g_hash_table_remove_all (priv->headers);
 		}
 	}
 
 	if (how & RSPAMD_MILTER_RESET_ADDR) {
 		if (session->addr) {
+			msg_debug_milter ("cleanup addr");
 			rspamd_inet_address_free (session->addr);
 			session->addr = NULL;
 		}
@@ -151,6 +164,7 @@ rspamd_milter_session_reset (struct rspa
 
 	if (how & RSPAMD_MILTER_RESET_MACRO) {
 		if (session->macros) {
+			msg_debug_milter ("cleanup macros");
 			g_hash_table_unref (session->macros);
 			session->macros = NULL;
 		}
@@ -1545,7 +1559,7 @@ rspamd_milter_send_task_results (struct 
 		msg_err_milter ("cannot find scan results, tempfail");
 		rspamd_milter_send_action (session, RSPAMD_MILTER_TEMPFAIL);
 
-		return;
+		goto cleanup;
 	}
 
 	elt = ucl_object_lookup (results, "action");
@@ -1554,7 +1568,7 @@ rspamd_milter_send_task_results (struct 
 		msg_err_milter ("cannot find action in results, tempfail");
 		rspamd_milter_send_action (session, RSPAMD_MILTER_TEMPFAIL);
 
-		return;
+		goto cleanup;
 	}
 
 	rspamd_action_from_str (ucl_object_tostring (elt), &action);
@@ -1614,7 +1628,6 @@ rspamd_milter_send_task_results (struct 
 			}
 
 			rspamd_milter_set_reply (session, rcode, xcode, reply);
-			rspamd_milter_send_action (session, RSPAMD_MILTER_REJECT);
 		}
 		break;
 	case METRIC_ACTION_SOFT_REJECT:
@@ -1629,7 +1642,6 @@ rspamd_milter_send_task_results (struct 
 		}
 
 		rspamd_milter_set_reply (session, rcode, xcode, reply);
-		rspamd_milter_send_action (session, RSPAMD_MILTER_REJECT);
 		break;
 
 	case METRIC_ACTION_REWRITE_SUBJECT:
@@ -1674,6 +1686,8 @@ cleanup:
 	rspamd_fstring_free (rcode);
 	rspamd_fstring_free (xcode);
 	rspamd_fstring_free (reply);
+
+	rspamd_milter_session_reset (session, RSPAMD_MILTER_RESET_ABORT);
 }
 
 void
