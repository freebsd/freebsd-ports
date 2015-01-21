--- src/cms_common.c.orig	2014-10-24 21:51:06.000000000 +0200
+++ src/cms_common.c	2015-01-16 10:00:34.000000000 +0100
@@ -45,7 +45,7 @@ struct digest_param {
 	SECOidTag digest_tag;
 	SECOidTag signature_tag;
 	SECOidTag digest_encryption_tag;
-	efi_guid_t *efi_guid;
+	const efi_guid_t *efi_guid;
 	int size;
 };
 
