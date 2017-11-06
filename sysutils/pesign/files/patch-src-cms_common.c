--- src/cms_common.c.orig	2014-10-24 19:51:06 UTC
+++ src/cms_common.c
@@ -45,7 +45,7 @@ struct digest_param {
 	SECOidTag digest_tag;
 	SECOidTag signature_tag;
 	SECOidTag digest_encryption_tag;
-	efi_guid_t *efi_guid;
+	const efi_guid_t *efi_guid;
 	int size;
 };
 
@@ -1664,25 +1664,6 @@ typedef struct {
 	SECItem oid;
 	SECItem keyhash;
 } KeyId;
-
-static const SEC_ASN1Template KeyIdTemplate[] = {
-	{.kind = SEC_ASN1_SEQUENCE,
-	 .offset = 0,
-	 .sub = NULL,
-	 .size = sizeof (KeyId),
-	},
-	{.kind = SEC_ASN1_OBJECT_ID,
-	 .offset = offsetof(KeyId, oid),
-	 .sub = &SEC_ObjectIDTemplate,
-	 .size = sizeof (SECItem),
-	},
-	{.kind = SEC_ASN1_OCTET_STRING,
-	 .offset = offsetof(KeyId, keyhash),
-	 .sub = NULL,
-	 .size = sizeof (SECItem),
-	},
-	{ 0 }
-};
 
 int
 generate_keys(cms_context *cms, PK11SlotInfo *slot,
