# Cast away warnings filling const strings
#
--- src/initextx.c.orig	2015-08-29 23:34:25 UTC
+++ src/initextx.c
@@ -252,8 +252,8 @@ SiSBuildBuiltInModeList(ScrnInfoPtr pScr
 
       current = new;
 
-      sprintf(current->name, "%dx%d", pSiS->SiS_Pr->SiS_RefIndex[i].XRes,
-				      pSiS->SiS_Pr->SiS_RefIndex[i].YRes);
+      sprintf((char *)current->name, "%dx%d", pSiS->SiS_Pr->SiS_RefIndex[i].XRes,
+					      pSiS->SiS_Pr->SiS_RefIndex[i].YRes);
 
       current->status = MODE_OK;
 
@@ -402,7 +402,7 @@ SiSBuildBuiltInModeList(ScrnInfoPtr pScr
 
 		  pSiS->AddedPlasmaModes = TRUE;
 
-		  strcpy(current->name, SiS_PlasmaMode[l].name);
+		  strcpy((char *)current->name, SiS_PlasmaMode[l].name);
 
 		  current->status = MODE_OK;
 
@@ -485,8 +485,8 @@ SiSBuildBuiltInModeList(ScrnInfoPtr pScr
 
 	    current = new;
 
-	    sprintf(current->name, "%dx%d", pSiS->SiS_Pr->CP_HDisplay[i],
-				pSiS->SiS_Pr->CP_VDisplay[i]);
+	    sprintf((char *)current->name, "%dx%d", pSiS->SiS_Pr->CP_HDisplay[i],
+						    pSiS->SiS_Pr->CP_VDisplay[i]);
 
 	    current->status = MODE_OK;
 
