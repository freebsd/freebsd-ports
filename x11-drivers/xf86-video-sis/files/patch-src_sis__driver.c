# Correct a string that should be const
# Cast away a warning filling a const string
#
--- src/sis_driver.c.orig	2017-01-17 22:45:12 UTC
+++ src/sis_driver.c
@@ -6065,7 +6065,7 @@ SISPreInit(ScrnInfoPtr pScrn, int flags)
 	        free(newm);
 		break;
 	     }
-	     strcpy(newm->name, tempm->name);
+	     strcpy((char *)newm->name, tempm->name);
 	     if(!pSiS->CRT2pScrn->monitor->Modes) pSiS->CRT2pScrn->monitor->Modes = newm;
 	     if(currentm) {
 	        currentm->next = newm;
