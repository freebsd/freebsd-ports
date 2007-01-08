--- addins/dl/mds/dal_classes.h.orig	Fri Jun 10 02:35:44 2005
+++ addins/dl/mds/dal_classes.h	Mon Jan  8 01:10:51 2007
@@ -455,7 +455,7 @@
 		DAL_DATABASE_INFO_REF_PTR &prefDatabase,
         PORT_MUTEX_HANDLE &Mutex);
 
-	CSSM_RETURN DAL_DATABASE_INFO_LIST::GetDBNamesAndParameters(
+	CSSM_RETURN GetDBNamesAndParameters(
 				CSSM_DL_DB_HANDLE DLDBHandle,
 				DAL_DB_OPEN_PARAM_PTR pParam);
 };
