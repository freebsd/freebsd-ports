--- usr/lib/pkcs11/common/tok_spec_struct.h.orig	2010-07-29 21:28:41.000000000 +0900
+++ usr/lib/pkcs11/common/tok_spec_struct.h	2010-10-20 00:17:28.288984976 +0900
@@ -308,9 +308,9 @@
 #define _TOK_SPECIFIC_STRUCT
 
 struct token_specific_struct{
-   CK_BYTE  token_directory[PATH_MAX];  // Used to be in the token_local.h as a #def
-   CK_BYTE  token_subdir[PATH_MAX];     // subdirectory
-   CK_BYTE  token_debug_tag[PATH_MAX];  // debug logging tag
+   CK_BYTE  *token_directory;  // Used to be in the token_local.h as a #def
+   CK_BYTE  *token_subdir;     // subdirectory
+   CK_BYTE  *token_debug_tag;  // debug logging tag
 
    CK_RV  (*t_init)(char *,CK_SLOT_ID);             // Initialization function
    int  (*t_slot2local)();       // convert the PKCS#11 slot to a local index
