
$FreeBSD$

--- modules/tm/t_reply.c.orig
+++ modules/tm/t_reply.c
@@ -686,6 +686,19 @@
 	/* if final response received at this branch, allow only INVITE 2xx */
 	if (Trans->uac[branch].last_received>=200
 			&& !(inv_through && Trans->uac[branch].last_received<300)) {
+		/* don't report on retranmissions */
+		if (Trans->uac[branch].last_received==new_code) {
+			DBG("DEBUG: final reply retrasnmission\n");
+			goto discard;
+		}
+		/* if you FR-timed-out, faked a local 408 and 487 came, don't
+		 * report on it either */
+		if (Trans->uac[branch].last_received==408 && new_code==487) {
+			DBG("DEBUG: 487 came for a timed-out branch\n");
+			goto discard;
+		}
+		/* this looks however how a very strange status rewrite attempt;
+		 * report on it */
 		LOG(L_ERR, "ERROR: t_should_relay: status rewrite by UAS: "
 			"stored: %d, received: %d\n",
 			Trans->uac[branch].last_received, new_code );
