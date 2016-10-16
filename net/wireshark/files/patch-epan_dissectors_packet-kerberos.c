--- epan/dissectors/packet-kerberos.c.orig	2016-10-04 18:27:49 UTC
+++ epan/dissectors/packet-kerberos.c
@@ -1068,66 +1068,7 @@ decrypt_krb5_data(proto_tree *tree, pack
 #define KRB5_MSG_ENC_KRB_CRED_PART	29	/* EncKrbCredPart */
 #define KRB5_MSG_ERROR			30	/* KRB-ERROR type */
 
-/* encryption type constants */
-#define KRB5_ENCTYPE_NULL		0
-#define KRB5_ENCTYPE_DES_CBC_CRC	1
-#define KRB5_ENCTYPE_DES_CBC_MD4	2
-#define KRB5_ENCTYPE_DES_CBC_MD5	3
-#define KRB5_ENCTYPE_DES_CBC_RAW	4
-#define KRB5_ENCTYPE_DES3_CBC_SHA	5
-#define KRB5_ENCTYPE_DES3_CBC_RAW	6
-#define KRB5_ENCTYPE_DES_HMAC_SHA1	8
-#define KRB5_ENCTYPE_DSA_SHA1_CMS	9
-#define KRB5_ENCTYPE_RSA_MD5_CMS	10
-#define KRB5_ENCTYPE_RSA_SHA1_CMS	11
-#define KRB5_ENCTYPE_RC2_CBC_ENV	12
-#define KRB5_ENCTYPE_RSA_ENV		13
-#define KRB5_ENCTYPE_RSA_ES_OEAP_ENV	14
-#define KRB5_ENCTYPE_DES_EDE3_CBC_ENV	15
-#define KRB5_ENCTYPE_DES3_CBC_SHA1	16
-#define KRB5_ENCTYPE_AES128_CTS_HMAC_SHA1_96 17
-#define KRB5_ENCTYPE_AES256_CTS_HMAC_SHA1_96 18
-#define KRB5_ENCTYPE_DES_CBC_MD5_NT	20
-#define KERB_ENCTYPE_RC4_HMAC		23
-#define KERB_ENCTYPE_RC4_HMAC_EXP	24
-#define KRB5_ENCTYPE_UNKNOWN		0x1ff
-#define KRB5_ENCTYPE_LOCAL_DES3_HMAC_SHA1	0x7007
-#define KRB5_ENCTYPE_RC4_PLAIN_EXP	0xffffff73
-#define KRB5_ENCTYPE_RC4_PLAIN		0xffffff74
-#define KRB5_ENCTYPE_RC4_PLAIN_OLD_EXP	0xffffff78
-#define KRB5_ENCTYPE_RC4_HMAC_OLD_EXP	0xffffff79
-#define KRB5_ENCTYPE_RC4_PLAIN_OLD	0xffffff7a
-#define KRB5_ENCTYPE_RC4_HMAC_OLD	0xffffff7b
-#define KRB5_ENCTYPE_DES_PLAIN		0xffffff7c
-#define KRB5_ENCTYPE_RC4_SHA		0xffffff7d
-#define KRB5_ENCTYPE_RC4_LM		0xffffff7e
-#define KRB5_ENCTYPE_RC4_PLAIN2		0xffffff7f
-#define KRB5_ENCTYPE_RC4_MD4		0xffffff80
-
-/* checksum types */
-#define KRB5_CHKSUM_NONE		0
-#define KRB5_CHKSUM_CRC32		1
-#define KRB5_CHKSUM_MD4			2
-#define KRB5_CHKSUM_KRB_DES_MAC		4
-#define KRB5_CHKSUM_KRB_DES_MAC_K	5
-#define KRB5_CHKSUM_MD5			7
-#define KRB5_CHKSUM_MD5_DES		8
-/* the following four come from packetcable */
-#define KRB5_CHKSUM_MD5_DES3		9
-#define KRB5_CHKSUM_HMAC_SHA1_DES3_KD	12
-#define KRB5_CHKSUM_HMAC_SHA1_DES3	13
-#define KRB5_CHKSUM_SHA1_UNKEYED	14
-#define KRB5_CHKSUM_HMAC_MD5		0xffffff76
-#define KRB5_CHKSUM_MD5_HMAC		0xffffff77
-#define KRB5_CHKSUM_RC4_MD5		0xffffff78
-#define KRB5_CHKSUM_MD25		0xffffff79
-#define KRB5_CHKSUM_DES_MAC_MD5		0xffffff7a
-#define KRB5_CHKSUM_DES_MAC		0xffffff7b
-#define KRB5_CHKSUM_REAL_CRC32		0xffffff7c
-#define KRB5_CHKSUM_SHA1		0xffffff7d
-#define KRB5_CHKSUM_LM			0xffffff7e
 #define KRB5_CHKSUM_GSSAPI		0x8003
-
 /*
  * For KERB_ENCTYPE_RC4_HMAC and KERB_ENCTYPE_RC4_HMAC_EXP, see
  *
@@ -1423,71 +1364,6 @@ static const value_string krb5_preauthen
 	{ 0                            , NULL },
 };
 
-#if 0
-static const value_string krb5_encryption_types[] = {
-	{ KRB5_ENCTYPE_NULL           , "NULL" },
-	{ KRB5_ENCTYPE_DES_CBC_CRC    , "des-cbc-crc" },
-	{ KRB5_ENCTYPE_DES_CBC_MD4    , "des-cbc-md4" },
-	{ KRB5_ENCTYPE_DES_CBC_MD5    , "des-cbc-md5" },
-	{ KRB5_ENCTYPE_DES_CBC_RAW    , "des-cbc-raw" },
-	{ KRB5_ENCTYPE_DES3_CBC_SHA   , "des3-cbc-sha" },
-	{ KRB5_ENCTYPE_DES3_CBC_RAW   , "des3-cbc-raw" },
-	{ KRB5_ENCTYPE_DES_HMAC_SHA1  , "des-hmac-sha1" },
-	{ KRB5_ENCTYPE_DSA_SHA1_CMS   , "dsa-sha1-cms" },
-	{ KRB5_ENCTYPE_RSA_MD5_CMS    , "rsa-md5-cms" },
-	{ KRB5_ENCTYPE_RSA_SHA1_CMS   , "rsa-sha1-cms" },
-	{ KRB5_ENCTYPE_RC2_CBC_ENV    , "rc2-cbc-env" },
-	{ KRB5_ENCTYPE_RSA_ENV        , "rsa-env" },
-	{ KRB5_ENCTYPE_RSA_ES_OEAP_ENV, "rsa-es-oeap-env" },
-	{ KRB5_ENCTYPE_DES_EDE3_CBC_ENV, "des-ede3-cbc-env" },
-	{ KRB5_ENCTYPE_DES3_CBC_SHA1  , "des3-cbc-sha1" },
-	{ KRB5_ENCTYPE_AES128_CTS_HMAC_SHA1_96  , "aes128-cts-hmac-sha1-96" },
-	{ KRB5_ENCTYPE_AES256_CTS_HMAC_SHA1_96  , "aes256-cts-hmac-sha1-96" },
-	{ KRB5_ENCTYPE_DES_CBC_MD5_NT  , "des-cbc-md5-nt" },
-	{ KERB_ENCTYPE_RC4_HMAC       , "rc4-hmac" },
-	{ KERB_ENCTYPE_RC4_HMAC_EXP   , "rc4-hmac-exp" },
-	{ KRB5_ENCTYPE_UNKNOWN        , "unknown" },
-	{ KRB5_ENCTYPE_LOCAL_DES3_HMAC_SHA1    , "local-des3-hmac-sha1" },
-	{ KRB5_ENCTYPE_RC4_PLAIN_EXP  , "rc4-plain-exp" },
-	{ KRB5_ENCTYPE_RC4_PLAIN      , "rc4-plain" },
-	{ KRB5_ENCTYPE_RC4_PLAIN_OLD_EXP, "rc4-plain-old-exp" },
-	{ KRB5_ENCTYPE_RC4_HMAC_OLD_EXP, "rc4-hmac-old-exp" },
-	{ KRB5_ENCTYPE_RC4_PLAIN_OLD  , "rc4-plain-old" },
-	{ KRB5_ENCTYPE_RC4_HMAC_OLD   , "rc4-hmac-old" },
-	{ KRB5_ENCTYPE_DES_PLAIN      , "des-plain" },
-	{ KRB5_ENCTYPE_RC4_SHA        , "rc4-sha" },
-	{ KRB5_ENCTYPE_RC4_LM         , "rc4-lm" },
-	{ KRB5_ENCTYPE_RC4_PLAIN2     , "rc4-plain2" },
-	{ KRB5_ENCTYPE_RC4_MD4        , "rc4-md4" },
-	{ 0                           , NULL },
-};
-
-static const value_string krb5_checksum_types[] = {
-	{ KRB5_CHKSUM_NONE            , "none" },
-	{ KRB5_CHKSUM_CRC32           , "crc32" },
-	{ KRB5_CHKSUM_MD4             , "md4" },
-	{ KRB5_CHKSUM_KRB_DES_MAC     , "krb-des-mac" },
-	{ KRB5_CHKSUM_KRB_DES_MAC_K   , "krb-des-mac-k" },
-	{ KRB5_CHKSUM_MD5             , "md5" },
-	{ KRB5_CHKSUM_MD5_DES         , "md5-des" },
-	{ KRB5_CHKSUM_MD5_DES3        , "md5-des3" },
-	{ KRB5_CHKSUM_HMAC_SHA1_DES3_KD, "hmac-sha1-des3-kd" },
-	{ KRB5_CHKSUM_HMAC_SHA1_DES3  , "hmac-sha1-des3" },
-	{ KRB5_CHKSUM_SHA1_UNKEYED    , "sha1 (unkeyed)" },
-	{ KRB5_CHKSUM_HMAC_MD5        , "hmac-md5" },
-	{ KRB5_CHKSUM_MD5_HMAC        , "md5-hmac" },
-	{ KRB5_CHKSUM_RC4_MD5         , "rc5-md5" },
-	{ KRB5_CHKSUM_MD25            , "md25" },
-	{ KRB5_CHKSUM_DES_MAC_MD5     , "des-mac-md5" },
-	{ KRB5_CHKSUM_DES_MAC         , "des-mac" },
-	{ KRB5_CHKSUM_REAL_CRC32      , "real-crc32" },
-	{ KRB5_CHKSUM_SHA1            , "sha1" },
-	{ KRB5_CHKSUM_LM              , "lm" },
-	{ KRB5_CHKSUM_GSSAPI	  , "gssapi-8003" },
-	{ 0                           , NULL },
-};
-#endif
-
 #define KRB5_AD_IF_RELEVANT			1
 #define KRB5_AD_INTENDED_FOR_SERVER		2
 #define KRB5_AD_INTENDED_FOR_APPLICATION_CLASS	3
@@ -4341,7 +4217,7 @@ dissect_kerberos_ChangePasswdData(gboole
 
 
 /*--- End of included file: packet-kerberos-fn.c ---*/
-#line 1985 "./asn1/kerberos/packet-kerberos-template.c"
+#line 1861 "./asn1/kerberos/packet-kerberos-template.c"
 
 /* Make wrappers around exported functions for now */
 int
@@ -5395,7 +5271,7 @@ void proto_register_kerberos(void) {
         NULL, HFILL }},
 
 /*--- End of included file: packet-kerberos-hfarr.c ---*/
-#line 2366 "./asn1/kerberos/packet-kerberos-template.c"
+#line 2242 "./asn1/kerberos/packet-kerberos-template.c"
 	};
 
 	/* List of subtrees */
@@ -5473,7 +5349,7 @@ void proto_register_kerberos(void) {
     &ett_kerberos_ChangePasswdData,
 
 /*--- End of included file: packet-kerberos-ettarr.c ---*/
-#line 2382 "./asn1/kerberos/packet-kerberos-template.c"
+#line 2258 "./asn1/kerberos/packet-kerberos-template.c"
 	};
 
 	static ei_register_info ei[] = {
