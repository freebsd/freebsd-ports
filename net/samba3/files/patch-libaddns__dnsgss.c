Index: libaddns/dnsgss.c
===================================================================
--- libaddns/dnsgss.c	(revision 25080)
+++ libaddns/dnsgss.c	(working copy)
@@ -219,11 +219,8 @@ DNS_ERROR dns_negotiate_sec_ctx( const c
 
 	gss_name_t targ_name;
 
-	krb5_principal host_principal;
-	krb5_context krb_ctx = NULL;
-
 	gss_OID_desc nt_host_oid_desc =
-		{ 10, (char *)"\052\206\110\206\367\022\001\002\002\002" };
+		{10, (char *)"\x2a\x86\x48\x86\xf7\x12\x01\x02\x02\x01"};
 
 	TALLOC_CTX *mem_ctx;
 
@@ -247,23 +244,13 @@ DNS_ERROR dns_negotiate_sec_ctx( const c
 		goto error;
 	}
 
-	krb5_init_context( &krb_ctx );
-	krb5_parse_name( krb_ctx, targetname, &host_principal );
-
-	/* don't free the principal until after you call
-	   gss_release_name() or else you'll get a segv
-	   as the krb5_copy_principal() does a structure 
-	   copy and not a deep copy.    --jerry*/
-
-	input_name.value = &host_principal;
-	input_name.length = sizeof( host_principal );
+	input_name.value = targetname;
+	input_name.length = strlen(targetname);
 
 	major = gss_import_name( &minor, &input_name,
 				 &nt_host_oid_desc, &targ_name );
 
 	if (major) {
-		krb5_free_principal( krb_ctx, host_principal );
-		krb5_free_context( krb_ctx );
 		err = ERROR_DNS_GSS_ERROR;
 		goto error;
 	}
@@ -273,11 +260,6 @@ DNS_ERROR dns_negotiate_sec_ctx( const c
 	
 	gss_release_name( &minor, &targ_name );
 
-	/* now we can free the principal */
-
-	krb5_free_principal( krb_ctx, host_principal );
-	krb5_free_context( krb_ctx );
-
  error:
 	TALLOC_FREE(mem_ctx);
 
