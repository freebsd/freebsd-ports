--- vmg/ifo_dump.c.orig	2003-06-25 18:12:43.000000000 +0200
+++ vmg/ifo_dump.c	2009-02-04 08:20:52.000000000 +0100
@@ -50,134 +50,12 @@
 
 
 static void print_ifo(char *path, int title) {
-  dvd_reader_t *dvd;
-  ifo_handle_t *h;
-  
-  dvd = DVDOpen(path);
+  dvd_reader_t *dvd = DVDOpen(path);
+
   if(!dvd) {
     fprintf(stderr, "Can't open disc %s!\n", path);
     return;
   }
 
-  if((h = ifoOpen(dvd, title)) == NULL)
-    return;
-    
-  if(h->vmgi_mat != NULL) {
-    
-    printf("VMG top level\n-------------\n");
-    ifoPrint_VMGI_MAT(h->vmgi_mat);
-      
-    printf("\nFirst Play PGC\n--------------\n");
-    ifoPrint_PGC(h->first_play_pgc);
-      
-    printf("\nTitle Track search pointer table\n");
-    printf(  "------------------------------------------------\n");
-    ifoPrint_TT_SRPT(h->tt_srpt);
-      
-    printf("\nMenu PGCI Unit table\n");
-    printf(  "--------------------\n");
-    if(h->vmgi_mat->vmgm_pgci_ut != 0) {
-      ifoPrint_PGCI_UT(h->pgci_ut);
-    } else 
-      printf("No Menu PGCI Unit table present\n");
-      
-    printf("\nParental Manegment Information table\n");
-    printf(  "------------------------------------\n");
-    if(h->vmgi_mat->ptl_mait != 0) {
-      ifoPrint_PTL_MAIT(h->ptl_mait);
-    } else
-      printf("No Parental Management Information present\n");
-      
-    printf("\nVideo Title Set Attribute Table\n");
-    printf(  "-------------------------------\n");
-    ifoPrint_VTS_ATRT(h->vts_atrt);
-
-      
-    printf("\nText Data Manager Information\n");
-    printf(  "-----------------------------\n");
-    if(h->vmgi_mat->txtdt_mgi != 0) {
-      //ifoPrint_TXTDT_MGI(h->txtdt_mgi);
-      printf("Can't print Text Data Manager Information yet\n");
-    } else
-      printf("No Text Data Manager Information present\n");
-      
-    if(1) {
-      
-      printf("\nCell Address table\n");
-      printf(  "-----------------\n");
-      if(h->vmgi_mat->vmgm_c_adt != 0) {
-	ifoPrint_C_ADT(h->menu_c_adt);
-      } else
-	printf("No Cell Address table present\n");
-      
-      printf("\nVideo Title set Menu VOBU address map\n");
-      printf(  "-----------------\n");
-      if(h->vmgi_mat->vmgm_vobu_admap != 0) {
-	ifoPrint_VOBU_ADMAP(h->menu_vobu_admap);
-      } else
-	printf("No Menu VOBU address map present\n");
-    }
-  }
-
-  if(h->vtsi_mat != NULL) {
-      
-    printf("VTS top level\n-------------\n");
-    ifoPrint_VTSI_MAT(h->vtsi_mat);
-      
-    printf("\nPart of title search pointer table information\n");
-    printf(  "----------------------------------------------\n");
-    ifoPrint_VTS_PTT_SRPT(h->vts_ptt_srpt);
-       
-    printf("\nPGCI Unit table\n");
-    printf(  "--------------------\n");
-    ifoPrint_PGCIT(h->vts_pgcit);
-      
-    printf("\nMenu PGCI Unit table\n");
-    printf(  "--------------------\n");
-    if(h->vtsi_mat->vtsm_pgci_ut != 0) {
-      ifoPrint_PGCI_UT(h->pgci_ut);
-    } else
-      printf("No Menu PGCI Unit table present\n");
-      
-    if(1) {
-      
-      printf("\nTime Map table\n");
-      printf(  "-----------------\n");
-      if(h->vtsi_mat->vts_tmapt != 0) {
-	ifoPrint_VTS_TMAPT(h->vts_tmapt);
-      } else
-	printf("No Time Map table present\n");
-      
-      printf("\nMenu Cell Address table\n");
-      printf(  "-----------------\n");
-      if(h->vtsi_mat->vtsm_c_adt != 0) {
-	ifoPrint_C_ADT(h->menu_c_adt);
-      } else
-	printf("No Cell Address table present\n");
-      
-      printf("\nVideo Title Set Menu VOBU address map\n");
-      printf(  "-----------------\n");
-      if(h->vtsi_mat->vtsm_vobu_admap != 0) {
-	ifoPrint_VOBU_ADMAP(h->menu_vobu_admap);
-      } else
-	printf("No Menu VOBU address map present\n");
-      
-      printf("\nCell Address table\n");
-      printf(  "-----------------\n");
-      ifoPrint_C_ADT(h->vts_c_adt);
-      
-      printf("\nVideo Title Set VOBU address map\n");
-      printf(  "-----------------\n");
-      ifoPrint_VOBU_ADMAP(h->vts_vobu_admap);
-      
-    }
-  }
-
-
-  /* Vob */
-  
+  ifo_print(dvd, title);
 }
-
-
-
-
