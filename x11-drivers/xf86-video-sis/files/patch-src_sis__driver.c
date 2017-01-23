# Correct a string that should be const
# Cast away a warning filling a const string
#
--- src/sis_driver.c.orig	2017-01-17 22:45:12 UTC
+++ src/sis_driver.c
@@ -1305,7 +1305,7 @@ SiSCopyModeNLink(ScrnInfoPtr pScrn, Disp
  * (Code base taken from mga driver)
  */
 static DisplayModePtr
-SiSGetModeFromName(char* str, DisplayModePtr i)
+SiSGetModeFromName(const char* str, DisplayModePtr i)
 {
     DisplayModePtr c = i;
     if(!i) return NULL;
@@ -6065,7 +6065,7 @@ SISPreInit(ScrnInfoPtr pScrn, int flags)
 	        free(newm);
 		break;
 	     }
-	     strcpy(newm->name, tempm->name);
+	     strcpy((char *)newm->name, tempm->name);
 	     if(!pSiS->CRT2pScrn->monitor->Modes) pSiS->CRT2pScrn->monitor->Modes = newm;
 	     if(currentm) {
 	        currentm->next = newm;
