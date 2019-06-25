--- MokManager.c.orig	2015-06-30 18:20:12 UTC
+++ MokManager.c
@@ -588,11 +588,11 @@ static void show_mok_info (EFI_GUID Type, void *Mok, U
 
 static EFI_STATUS list_keys (void *KeyList, UINTN KeyListSize, CHAR16 *title)
 {
-	INTN MokNum = 0;
+	UINT32 MokNum = 0;
 	MokListNode *keys = NULL;
 	UINT32 key_num = 0;
 	CHAR16 **menu_strings;
-	int i;
+	UINT32 i;
 
 	if (KeyListSize < (sizeof(EFI_SIGNATURE_LIST) +
 			   sizeof(EFI_SIGNATURE_DATA))) {
@@ -1037,7 +1037,8 @@ static EFI_STATUS write_back_mok_list (MokListNode *li
 			continue;
 
 		DataSize += sizeof(EFI_SIGNATURE_LIST);
-		if (CompareGuid(&(list[i].Type), &CertType) == 0)
+		if (CompareMem(&(list[i].Type), &CertType,
+			       sizeof(EFI_GUID)) == 0)
 			DataSize += sizeof(EFI_GUID);
 		DataSize += list[i].MokSize;
 	}
@@ -1059,7 +1060,8 @@ static EFI_STATUS write_back_mok_list (MokListNode *li
 		CertList->SignatureType = list[i].Type;
 		CertList->SignatureHeaderSize = 0;
 
-		if (CompareGuid(&(list[i].Type), &CertType) == 0) {
+		if (CompareMem(&(list[i].Type), &CertType,
+			       sizeof(EFI_GUID)) == 0) {
 			CertList->SignatureListSize = list[i].MokSize +
 						      sizeof(EFI_SIGNATURE_LIST) +
 						      sizeof(EFI_GUID);
@@ -1100,7 +1102,8 @@ static void delete_cert (void *key, UINT32 key_size,
 	int i;
 
 	for (i = 0; i < mok_num; i++) {
-		if (CompareGuid(&(mok[i].Type), &CertType) != 0)
+		if (CompareMem(&(mok[i].Type), &CertType,
+			       sizeof(EFI_GUID)) != 0)
 			continue;
 
 		if (mok[i].MokSize == key_size &&
@@ -1151,7 +1154,7 @@ static void delete_hash_in_list (EFI_GUID Type, UINT8 
 	sig_size = hash_size + sizeof(EFI_GUID);
 
 	for (i = 0; i < mok_num; i++) {
-		if ((CompareGuid(&(mok[i].Type), &Type) != 0) ||
+		if ((CompareMem(&(mok[i].Type), &Type, sizeof(EFI_GUID)) != 0) ||
 		    (mok[i].MokSize < sig_size))
 			continue;
 
@@ -1322,7 +1325,8 @@ static EFI_STATUS delete_keys (void *MokDel, UINTN Mok
 
 	/* Search and destroy */
 	for (i = 0; i < del_num; i++) {
-		if (CompareGuid(&(del_key[i].Type), &CertType) == 0) {
+		if (CompareMem(&(del_key[i].Type), &CertType,
+			       sizeof(EFI_GUID)) == 0) {
 			delete_cert(del_key[i].Mok, del_key[i].MokSize,
 				    mok, mok_num);
 		} else if (is_sha2_hash(del_key[i].Type)) {
