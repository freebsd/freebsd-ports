Index: src/plugins/pgpcore/sgpgme.c
===================================================================
RCS file: //claws/src/plugins/pgpcore/Attic/sgpgme.c,v
retrieving revision 1.1.2.65
retrieving revision 1.1.2.66
diff -u -r1.1.2.65 -r1.1.2.66
--- src/plugins/pgpcore/sgpgme.c	20 Oct 2009 17:40:30 -0000	1.1.2.65
+++ src/plugins/pgpcore/sgpgme.c	16 Jan 2010 18:19:42 -0000	1.1.2.66
@@ -860,15 +860,17 @@
 	if (!err)
 		err = gpgme_op_keylist_next(ctx, &key);
 	gpgme_op_keylist_end(ctx);
-	gpgme_release(ctx);
 	if (gpg_err_code(err) == GPG_ERR_EOF) {
 		if (gpgme_get_protocol(ctx) != GPGME_PROTOCOL_CMS) {
 			gpgme_set_protocol(ctx, GPGME_PROTOCOL_CMS);
 			goto check_again;
 		}
+		gpgme_release(ctx);
 		return FALSE;
-	} else
+	} else {
+		gpgme_release(ctx);
 		return TRUE;
+	}
 }
 
 void sgpgme_check_create_key(void)


