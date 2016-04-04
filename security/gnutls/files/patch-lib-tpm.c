--- lib/tpm.c.orig	2015-09-26 12:02:10 UTC
+++ lib/tpm.c
@@ -71,7 +71,6 @@ typedef TSS_RESULT (*Tspi_DecodeBER_TssB
 typedef TSS_RESULT (*Tspi_Context_LoadKeyByBlob_func)(TSS_HCONTEXT, TSS_HKEY, UINT32, BYTE*, TSS_HKEY*);
 typedef TSS_RESULT (*Tspi_Policy_AssignToObject_func)(TSS_HPOLICY, TSS_HOBJECT);
 typedef TSS_RESULT (*Tspi_GetAttribData_func)(TSS_HOBJECT, TSS_FLAG, TSS_FLAG, UINT32*, BYTE**);
-typedef TSS_RESULT (*Tspi_Context_GetTpmObject_func)(TSS_HCONTEXT, TSS_HTPM*);
 typedef TSS_RESULT (*Tspi_TPM_StirRandom_func)(TSS_HTPM, UINT32, BYTE*);
 typedef TSS_RESULT (*Tspi_SetAttribUint32_func)(TSS_HOBJECT, TSS_FLAG, TSS_FLAG, UINT32);
 typedef TSS_RESULT (*Tspi_EncodeDER_TssBlob_func)(UINT32, BYTE*, UINT32, UINT32*, BYTE*);
