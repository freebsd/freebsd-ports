--- buhg/dirzkart.c.orig	Mon Aug 26 03:46:07 2002
+++ buhg/dirzkart.c	Wed Oct  8 19:59:48 2003
@@ -660,7 +660,7 @@
   case FK1:       /*Помощь*/
    GDITE();
    
-   sprintf(strsql,"%s/doc/%s",putnansi,"matu3.txt");
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,"matu3.txt");
    prosf(strsql);
    if(kolstr > 0)
       goto naz;
@@ -1101,7 +1101,7 @@
 
   case FK1:
     GDITE();
-    sprintf(bros,"%s/doc/%s",putnansi,"matu3_1.txt");
+    sprintf(bros,"%s/%s",ICEB_DOC_PATH,"matu3_1.txt");
     prosf(bros);
     goto naz;
 
@@ -1324,7 +1324,7 @@
 short mbz) //0-сена изменилась 1-нет*/
 {
 SQL_str         row,row1,row2;
-long		vrem;
+time_t		vrem;
 char		strsql[300];
 long		kolstr;
 short		d,m,g;
