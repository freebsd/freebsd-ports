--- plugins/omprog/omprog.c.orig	2017-05-15 09:41:19 UTC
+++ plugins/omprog/omprog.c
@@ -231,6 +231,7 @@ execBinary(wrkrInstanceData_t *pWrkrData
 	sigset_t set;
 	char errStr[1024];
 	char *newenviron[] = { NULL };
+	char *emptyArgv[] = { NULL };
 
 	fclose(stdin);
 	if(dup(fdStdin) == -1) {
@@ -277,6 +278,9 @@ execBinary(wrkrInstanceData_t *pWrkrData
 	alarm(0);
 
 	/* finally exec child */
+	if(pWrkrData->pData->aParams==NULL){
+		pWrkrData->pData->aParams=emptyArgv;
+	}
 	iRet = execve((char*)pWrkrData->pData->szBinary, pWrkrData->pData->aParams, newenviron);
 	if(iRet == -1) {
 		/* Note: this will go to stdout of the **child**, so rsyslog will never
