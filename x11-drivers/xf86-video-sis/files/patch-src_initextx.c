# Cast away warnings filling const strings
#
--- src/initextx.c.orig	2019-07-26 23:38:52 UTC
+++ src/initextx.c
@@ -252,7 +252,7 @@ SiSBuildBuiltInModeList(ScrnInfoPtr pScrn, BOOLEAN inc
 
       current = new;
 
-      sprintf(current->name, "%hu%hu", pSiS->SiS_Pr->SiS_RefIndex[i].XRes,
+      sprintf((char *)current->name, "%hu%hu", pSiS->SiS_Pr->SiS_RefIndex[i].XRes,
 				      pSiS->SiS_Pr->SiS_RefIndex[i].YRes);
 
       current->status = MODE_OK;
@@ -402,7 +402,7 @@ SiSBuildBuiltInModeList(ScrnInfoPtr pScrn, BOOLEAN inc
 
 		  pSiS->AddedPlasmaModes = TRUE;
 
-		  strcpy(current->name, SiS_PlasmaMode[l].name);
+		  strcpy((char *)current->name, SiS_PlasmaMode[l].name);
 
 		  current->status = MODE_OK;
 
@@ -485,8 +485,8 @@ SiSBuildBuiltInModeList(ScrnInfoPtr pScrn, BOOLEAN inc
 
 	    current = new;
 
-	    sprintf(current->name, "%dx%d", pSiS->SiS_Pr->CP_HDisplay[i],
-				pSiS->SiS_Pr->CP_VDisplay[i]);
+	    sprintf((char *)current->name, "%dx%d", pSiS->SiS_Pr->CP_HDisplay[i],
+						    pSiS->SiS_Pr->CP_VDisplay[i]);
 
 	    current->status = MODE_OK;
 
