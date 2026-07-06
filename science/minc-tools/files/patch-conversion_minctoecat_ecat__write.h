--- conversion/minctoecat/ecat_write.h.orig	2023-04-11 00:36:27 UTC
+++ conversion/minctoecat/ecat_write.h
@@ -39,9 +39,9 @@ typedef enum {
   BitData
 } MatrixDataType;
 
-MatrixErrorCode matrix_errno;
+extern MatrixErrorCode matrix_errno;
 
-char matrix_errtxt[132];
+extern char matrix_errtxt[132];
 
 typedef struct XMAIN_HEAD {
   char magic_number[14];
