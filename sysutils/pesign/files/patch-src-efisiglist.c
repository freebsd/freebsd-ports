--- src/efisiglist.c.orig	2014-10-24 21:51:06.000000000 +0200
+++ src/efisiglist.c	2015-01-16 10:01:33.000000000 +0100
@@ -38,11 +38,11 @@ struct hash_param {
 
 static struct hash_param hash_params[] = {
 	{.name = "sha256",
-	 .guid = &efi_guid_sha256,
+	 .guid = (void *)&efi_guid_sha256,
 	 .size = 32,
 	},
 	{.name = "sha1",
-	 .guid = &efi_guid_sha1,
+	 .guid = (void *)&efi_guid_sha1,
 	 .size = 20,
 	},
 };
