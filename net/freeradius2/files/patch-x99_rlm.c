--- src/modules/rlm_x99_token/x99_rlm.c.orig	Wed Aug 18 10:52:56 2004
+++ src/modules/rlm_x99_token/x99_rlm.c	Wed Aug 18 10:53:43 2004
@@ -544,8 +544,6 @@
 			"auth: bad state for [%s]: expired", username);
 		return RLM_MODULE_REJECT;
 	    }
-good_state:
-	    /* State is good! */
 
 	} else {
 	    /* This should only happen if the authorize code didn't run. */
@@ -555,6 +553,9 @@
 	    return RLM_MODULE_FAIL;
 	}
     } /* if (!fast_sync) */
+
+good_state:
+	    /* State is good! */
 
     /* Get the time of the last authentication. */
     if (x99_get_last_auth(inst->syncdir, username, &last_auth) != 0) {
