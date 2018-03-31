--- src/condor_io/condor_auth_kerberos.cpp.orig	2018-03-29 12:44:08 UTC
+++ src/condor_io/condor_auth_kerberos.cpp
@@ -80,7 +80,7 @@ static void (KRB5_CALLCONV *krb5_free_cr
 static void (KRB5_CALLCONV *krb5_free_keyblock_ptr)(krb5_context, register krb5_keyblock *) = NULL;
 static void (KRB5_CALLCONV *krb5_free_principal_ptr)(krb5_context, krb5_principal) = NULL;
 static void (KRB5_CALLCONV *krb5_free_ticket_ptr)(krb5_context, krb5_ticket *) = NULL;
-static krb5_error_code (KRB5_CALLCONV *krb5_fwd_tgt_creds_ptr)(krb5_context, krb5_auth_context, char *, krb5_principal, krb5_principal, krb5_ccache, int, krb5_data *) = NULL;
+static krb5_error_code (KRB5_CALLCONV *krb5_fwd_tgt_creds_ptr)(krb5_context, krb5_auth_context, const char *, krb5_principal, krb5_principal, krb5_ccache, int, krb5_data *) = NULL;
 static krb5_error_code (KRB5_CALLCONV *krb5_get_credentials_ptr)(krb5_context, krb5_flags, krb5_ccache, krb5_creds *, krb5_creds **) = NULL;
 // The presence of KRB5_RESPONDER_QUESTION_PASSWORD is a hacky substitute
 // for detecting the version of Kerberos where the function signature
