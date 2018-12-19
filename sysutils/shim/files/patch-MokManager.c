--- MokManager.c.orig	2015-06-30 18:20:12 UTC
+++ MokManager.c
@@ -588,11 +588,11 @@ static void show_mok_info (EFI_GUID Type
 
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
