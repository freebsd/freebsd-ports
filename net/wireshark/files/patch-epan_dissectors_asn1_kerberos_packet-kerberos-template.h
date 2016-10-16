--- epan/dissectors/asn1/kerberos/packet-kerberos-template.h.orig	2016-10-04 18:27:46 UTC
+++ epan/dissectors/asn1/kerberos/packet-kerberos-template.h
@@ -100,42 +100,6 @@ void read_keytab_file_from_preferences(v
 
 #endif /* HAVE_KERBEROS */
 
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
 #include "packet-kerberos-exp.h"
 
 #ifdef __cplusplus
