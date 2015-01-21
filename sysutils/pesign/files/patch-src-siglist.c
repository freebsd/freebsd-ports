--- src/siglist.c.orig	2014-10-24 21:51:06.000000000 +0200
+++ src/siglist.c	2015-01-16 10:02:50.000000000 +0100
@@ -60,7 +60,7 @@ struct signature_list {
 };
 
 struct sig_type {
-	efi_guid_t *type;
+	const efi_guid_t *type;
 	uint32_t size;
 };
 
