--- library/adkrb5.c.orig	2022-09-28 17:04:28 UTC
+++ library/adkrb5.c
@@ -250,7 +250,7 @@ _adcli_krb5_get_keyblock (krb5_context k5,
 	krb5_error_code code;
 
 	code = krb5_kt_start_seq_get (k5, keytab, &cursor);
-	if (code == KRB5_KT_END || code == ENOENT)
+	if (code == KRB5_KT_END || code == KRB5_KT_NOTFOUND)
 		return 0;
 	else if (code != 0)
 		return code;
@@ -303,7 +303,7 @@ _adcli_krb5_keytab_copy_entries (krb5_context k5,
 		code = _adcli_krb5_get_keyblock (k5, keytab, &entry.key,
 		                                 match_enctype_and_kvno, &closure);
 		if (code != 0 || closure.matched == 0) {
-			return code != 0 ? code : ENOKEY;
+			return code != 0 ? code : KRB5_KT_NOTFOUND;
 		}
 
 		entry.principal = principal;
