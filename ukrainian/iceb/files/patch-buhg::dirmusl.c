--- buhg/dirmusl.c.orig	Mon Aug 26 03:46:07 2002
+++ buhg/dirmusl.c	Wed Oct  8 19:59:21 2003
@@ -230,7 +230,7 @@
 
   case FK1:   /*Помощь*/
    GDITE();
-   sprintf(strsql,"%s/doc/%s",putnansi,"matu2_1_2b.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu2_1_2b.txt");
    prosf(strsql);
    clear();
    if(kolstr > 0)
@@ -337,7 +337,7 @@
 char            naiuslz[100],eiz[20];
 double          kolihz,cenaz,ndsz;
 char		strsql[500];
-long		vrem;
+time_t		vrem;
 
 
 VV->VVOD_SPISOK_add_ZAG(catgets(fils,132,3,"Ввод и корректировка услуг."));
