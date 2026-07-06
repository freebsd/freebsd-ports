--- misc/openvas-krb5.c.orig	2026-06-22 23:37:28.758531000 -0700
+++ misc/openvas-krb5.c	2026-06-22 23:38:15.469364000 -0700
@@ -337,12 +337,14 @@
   size_t user_principal_len = user->user.len + creds->realm.len + 1;
   size_t user_principal_cap = user_principal_len + 1;
 
+  gss_name_t gss_username = GSS_C_NO_NAME;
+  gss_cred_id_t cred = GSS_C_NO_CREDENTIAL;
+
   OKrb5ErrorCode result = O_KRB5_SUCCESS;
   ALLOCATE_AND_CHECK (user_principal, char, user_principal_cap, result);
   snprintf (user_principal, user_principal_cap, "%s@%s",
             (char *) user->user.data, (char *) creds->realm.data);
 
-  gss_name_t gss_username = GSS_C_NO_NAME;
   OM_uint32 maj_stat;
   OM_uint32 min_stat;
   // OM_uint32 dummy_min_stat;
@@ -369,7 +371,6 @@
     .elements = elements,
     .count = ARRAY_SIZE (elements) - 1, /* without gss_mech_spnego */
   };
-  gss_cred_id_t cred = GSS_C_NO_CREDENTIAL;
 
   maj_stat =
     gss_import_name (&min_stat, &userbuf, GSS_C_NT_USER_NAME, &gss_username);
