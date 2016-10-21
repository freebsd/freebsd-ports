--- epan/dissectors/packet-spnego.c.orig	2016-10-04 18:27:52 UTC
+++ epan/dissectors/packet-spnego.c
@@ -775,6 +775,9 @@ dissect_spnego_krb5(tvbuff_t *tvb, packe
 #ifndef KEYTYPE_ARCFOUR_56
 # define KEYTYPE_ARCFOUR_56 24
 #endif
+#ifndef KEYTYPE_ARCFOUR_HMAC
+# define KEYTYPE_ARCFOUR_HMAC 23
+#endif
 /* XXX - We should probably do a configure-time check for this instead */
 #ifndef KRB5_KU_USAGE_SEAL
 # define KRB5_KU_USAGE_SEAL 22
@@ -1299,7 +1302,7 @@ dissect_spnego_krb5_wrap_base(tvbuff_t *
 			decrypt_gssapi_krb_arcfour_wrap(tree,
 				pinfo,
 				tvb,
-				KERB_ENCTYPE_RC4_HMAC,
+				KEYTYPE_ARCFOUR_HMAC,
 				gssapi_encrypt);
 #endif /* HAVE_HEIMDAL_KERBEROS || HAVE_MIT_KERBEROS */
 		}
@@ -1966,7 +1969,7 @@ void proto_register_spnego(void) {
         NULL, HFILL }},
 
 /*--- End of included file: packet-spnego-hfarr.c ---*/
-#line 1421 "./asn1/spnego/packet-spnego-template.c"
+#line 1424 "./asn1/spnego/packet-spnego-template.c"
 	};
 
 	/* List of subtrees */
@@ -1989,7 +1992,7 @@ void proto_register_spnego(void) {
     &ett_spnego_InitialContextToken_U,
 
 /*--- End of included file: packet-spnego-ettarr.c ---*/
-#line 1431 "./asn1/spnego/packet-spnego-template.c"
+#line 1434 "./asn1/spnego/packet-spnego-template.c"
 	};
 
 	static ei_register_info ei[] = {
