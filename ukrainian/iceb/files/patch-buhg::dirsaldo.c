--- buhg/dirsaldo.c.orig	Mon Aug 26 03:46:07 2002
+++ buhg/dirsaldo.c	Wed Oct  8 19:49:15 2003
@@ -340,9 +340,9 @@
   case FK1:  /*Получить подсказку*/
     GDITE();
     if(tz[0] == '0')
-      sprintf(strsql,"%s/doc/buhg4_4.txt",putnansi);
+      sprintf(strsql,"%s/buhg4_4.txt",ICEB_DOC_PATH);
     if(tz[0] == '1')
-      sprintf(strsql,"%s/doc/buhg4_5.txt",putnansi);
+      sprintf(strsql,"%s/buhg4_5.txt",ICEB_DOC_PATH);
 
  /*
     printw("strsql=%s\n",strsql);
@@ -612,7 +612,7 @@
 char		korz[20];
 struct OPSHET	shetv;
 int		ktoi=getuid();
-long		vrem;
+time_t		vrem;
 char		strsql[300];
 SQL_str         row;
 int		i;
