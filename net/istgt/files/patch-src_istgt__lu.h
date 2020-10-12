--- src/istgt_lu.h.orig	2012-08-27 11:46:50 UTC
+++ src/istgt_lu.h
@@ -277,13 +277,13 @@ enum {
 	ISTGT_LU_TASK_RESULT_IMMEDIATE = 0,
 	ISTGT_LU_TASK_RESULT_QUEUE_OK = 1,
 	ISTGT_LU_TASK_RESULT_QUEUE_FULL = 2,
-} ISTGT_LU_TASK_RESULT;
+} /* ISTGT_LU_TASK_RESULT */;
 
 enum {
 	ISTGT_LU_TASK_RESPONSE = 0,
 	ISTGT_LU_TASK_REQPDU = 1,
 	ISTGT_LU_TASK_REQUPDPDU = 2,
-} ISTGT_LU_TASK_TYPE;
+} /* ISTGT_LU_TASK_TYPE */;
 
 typedef struct istgt_lu_task_t {
 	int type;
