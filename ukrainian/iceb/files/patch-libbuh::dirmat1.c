--- libbuh/dirmat1.c.orig	Mon Aug 26 03:46:09 2002
+++ libbuh/dirmat1.c	Wed Oct  8 18:51:45 2003
@@ -36,7 +36,7 @@
 char ignor[]) //Список кодов которые игнорируются при просмотре
 {
 struct  tm      *bf;
-long            tmm;
+time_t          tmm;
 int             K;
 int		prc;
 int             i=0;
@@ -550,7 +550,7 @@
        goto naz1;
       }     
     }
-   sprintf(strsql,"%s/doc/%s",putnansi,imaf);
+   sprintf(strsql,"%s/%s",ICEB_DOC_PATH,imaf);
 
 /*
    printw("strsql=%s\n",strsql);
