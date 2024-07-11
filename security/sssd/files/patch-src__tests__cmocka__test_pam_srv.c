--- src/tests/cmocka/test_pam_srv.c.orig	2020-03-17 13:31:28 UTC
+++ src/tests/cmocka/test_pam_srv.c
@@ -1177,7 +1177,7 @@ void test_pam_open_session(void **state)
 
     /* make sure pam_status is not touched by setting it to a value which is
      * not used by SSSD. */
-    pam_test_ctx->exp_pam_status = _PAM_RETURN_VALUES;
+    pam_test_ctx->exp_pam_status = PAM_NUM_ERRORS;
     set_cmd_cb(test_pam_simple_check);
     ret = sss_cmd_execute(pam_test_ctx->cctx, SSS_PAM_OPEN_SESSION,
                           pam_test_ctx->pam_cmds);
