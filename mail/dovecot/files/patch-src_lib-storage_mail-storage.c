--- src/lib-storage/mail-storage.c.orig	2019-07-12 10:46:25 UTC
+++ src/lib-storage/mail-storage.c
@@ -1040,10 +1040,10 @@ mailbox_name_verify_extra_separators(const char *vname
 }
 
 static bool
-mailbox_verify_name_prefix(struct mailbox *box, const char **error_r)
+mailbox_verify_name_prefix(struct mail_namespace *ns, const char **vnamep,
+			   const char **error_r)
 {
-	const char *vname = box->vname;
-	struct mail_namespace *ns = box->list->ns;
+	const char *vname = *vnamep;
 
 	if (ns->prefix_len == 0)
 		return TRUE;
@@ -1071,6 +1071,7 @@ mailbox_verify_name_prefix(struct mailbox *box, const 
 			return FALSE;
 		}
 	}
+	*vnamep = vname;
 	return TRUE;
 }
 
@@ -1085,7 +1086,9 @@ int mailbox_verify_name(struct mailbox *box)
 		return 0;
 	}
 
-	if (!mailbox_verify_name_prefix(box, &error)) {
+	/* Verify the namespace prefix here. Change vname to skip the prefix
+	   for the following checks. */
+	if (!mailbox_verify_name_prefix(box->list->ns, &vname, &error)) {
 		mail_storage_set_error(box->storage, MAIL_ERROR_PARAMS,
 			t_strdup_printf("Invalid mailbox name '%s': %s",
 					str_sanitize(vname, 80), error));
