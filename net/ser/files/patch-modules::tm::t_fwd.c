
$FreeBSD$

--- modules/tm/t_fwd.c.orig
+++ modules/tm/t_fwd.c
@@ -359,6 +359,15 @@
 		DBG("DEBUG: e2e_cancel: e2e cancel -- no more pending branches\n");
 		t_reply( t_cancel, cancel_msg, 200, CANCEL_DONE );
 	}
+
+#ifdef LOCAL_487
+
+	/* local 487s have been deprecated -- it better handles
+	 * race conditions (UAS sending 200); hopefuly there are
+	 * no longer UACs who go crazy waiting for the 487 whose
+	 * forwarding is being blocked by other unreponsive branch
+	 */
+
 	/* we could await downstream UAS's 487 replies; however,
 	   if some of the branches does not do that, we could wait
 	   long time and annoy upstream UAC which wants to see 
@@ -375,6 +384,7 @@
 	   "can't reply twice"
 	*/
 	t_reply(t_invite, t_invite->uas.request, 487, CANCELLED );
+#endif
 }
 
 
