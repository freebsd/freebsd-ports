--- usr/lib/pkcs11/cca_stdll/tok_spec_struct.h.orig	2010-07-29 21:28:41.000000000 +0900
+++ usr/lib/pkcs11/cca_stdll/tok_spec_struct.h	2010-10-20 00:08:00.317982423 +0900
@@ -22,9 +22,9 @@
 #define _TOK_SPECIFIC_STRUCT
 
 struct token_specific_struct{
-   CK_BYTE  token_directory[2048];  // Used to be in the token_local.h as a #def
-   CK_BYTE  token_subdir[2048];     // subdirectory
-   CK_BYTE  token_debug_tag[2048];  // debug logging tag
+   CK_BYTE  *token_directory;  // Used to be in the token_local.h as a #def
+   CK_BYTE  *token_subdir;     // subdirectory
+   CK_BYTE  *token_debug_tag;  // debug logging tag
 
    CK_RV  (*t_init)(char *,CK_SLOT_ID);             // Initialization function
    int  (*t_slot2local)();       // convert the PKCS#11 slot to a local index
