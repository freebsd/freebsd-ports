--- lib/tpm.c.orig	2016-12-19 14:10:59 UTC
+++ lib/tpm.c
@@ -72,7 +72,6 @@ typedef TSS_RESULT (*Tspi_Context_LoadKe
 typedef TSS_RESULT (*Tspi_Policy_AssignToObject_func)(TSS_HPOLICY, TSS_HOBJECT);
 typedef TSS_RESULT (*Tspi_GetAttribData_func)(TSS_HOBJECT, TSS_FLAG, TSS_FLAG, UINT32*, BYTE**);
 typedef TSS_RESULT (*Tspi_GetAttribUint32_func)(TSS_HOBJECT, TSS_FLAG, TSS_FLAG, UINT32*);
-typedef TSS_RESULT (*Tspi_Context_GetTpmObject_func)(TSS_HCONTEXT, TSS_HTPM*);
 typedef TSS_RESULT (*Tspi_TPM_StirRandom_func)(TSS_HTPM, UINT32, BYTE*);
 typedef TSS_RESULT (*Tspi_SetAttribUint32_func)(TSS_HOBJECT, TSS_FLAG, TSS_FLAG, UINT32);
 typedef TSS_RESULT (*Tspi_EncodeDER_TssBlob_func)(UINT32, BYTE*, UINT32, UINT32*, BYTE*);
