--- libbuh/vmat1.c.orig	Tue Aug 13 03:58:34 2002
+++ libbuh/vmat1.c	Wed Oct  8 18:54:01 2003
@@ -27,7 +27,7 @@
 SQL_str         row;
 char		strsql[500];
 char		kodz[12];
-long		vrem;
+time_t		vrem;
 int		vo;
 char		bros[100];
 short		metprov;
@@ -43,7 +43,7 @@
 struct  passwd  *ktor; /*Кто работает*/
 struct  passwd  *ktoz; /*Кто записал*/
 int             kt;
-long            vr;
+time_t          vr;
 int		nomkod=1;
 
 VVOD		SOOB(1);
@@ -986,7 +986,7 @@
         clear();
         goto naz1;
        }
-      sprintf(strsql,"%s/doc/%s",putnansi,imaf);
+      sprintf(strsql,"%s/%s",ICEB_DOC_PATH,imaf);
 
    /*
       printw("strsql=%s\n",strsql);
@@ -1359,7 +1359,7 @@
 naik='%s',\
 ktoz=%d,\
 vrem=%ld,\
-vido=%d,
+vido=%d, \
 sheta='%s',\
 prov=%d \
 where kod = '%s'",
