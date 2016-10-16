--- epan/dissectors/asn1/spnego/packet-spnego-template.c.orig	2016-10-04 18:27:47 UTC
+++ epan/dissectors/asn1/spnego/packet-spnego-template.c
@@ -323,6 +323,9 @@ dissect_spnego_krb5(tvbuff_t *tvb, packe
 #ifndef KEYTYPE_ARCFOUR_56
 # define KEYTYPE_ARCFOUR_56 24
 #endif
+#ifndef KEYTYPE_ARCFOUR_HMAC
+# define KEYTYPE_ARCFOUR_HMAC 23
+#endif
 /* XXX - We should probably do a configure-time check for this instead */
 #ifndef KRB5_KU_USAGE_SEAL
 # define KRB5_KU_USAGE_SEAL 22
@@ -847,7 +850,7 @@ dissect_spnego_krb5_wrap_base(tvbuff_t *
 			decrypt_gssapi_krb_arcfour_wrap(tree,
 				pinfo,
 				tvb,
-				KERB_ENCTYPE_RC4_HMAC,
+				KEYTYPE_ARCFOUR_HMAC,
 				gssapi_encrypt);
 #endif /* HAVE_HEIMDAL_KERBEROS || HAVE_MIT_KERBEROS */
 		}
