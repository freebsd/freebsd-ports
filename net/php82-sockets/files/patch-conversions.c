--- conversions.c.orig	2022-06-11 20:21:26 UTC
+++ conversions.c
@@ -1309,11 +1309,6 @@ static const field_descriptor descriptors_ucred[] = {
 		{"uid", sizeof("uid"), 1, offsetof(struct sockcred2, sc_euid), from_zval_write_uid_t, to_zval_read_uid_t},
 		/* the type gid_t is the same as uid_t: */
 		{"gid", sizeof("gid"), 1, offsetof(struct sockcred2, sc_egid), from_zval_write_uid_t, to_zval_read_uid_t},
-#elif defined(LOCAL_CREDS)
-		{"pid", sizeof("pid"), 1, offsetof(struct sockcred, sc_pid), from_zval_write_pid_t, to_zval_read_pid_t},
-		{"uid", sizeof("uid"), 1, offsetof(struct sockcred, sc_euid), from_zval_write_uid_t, to_zval_read_uid_t},
-		/* the type gid_t is the same as uid_t: */
-		{"gid", sizeof("gid"), 1, offsetof(struct sockcred, sc_egid), from_zval_write_uid_t, to_zval_read_uid_t},
 #elif defined(ANC_CREDS_CMSGCRED)
 		{"pid", sizeof("pid"), 1, offsetof(struct cmsgcred, cmcred_pid), from_zval_write_pid_t, to_zval_read_pid_t},
 		{"uid", sizeof("uid"), 1, offsetof(struct cmsgcred, cmcred_uid), from_zval_write_uid_t, to_zval_read_uid_t},
