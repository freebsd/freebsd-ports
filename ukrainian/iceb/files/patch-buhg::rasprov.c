--- buhg/rasprov.c.orig	Wed Oct  8 19:53:24 2003
+++ buhg/rasprov.c	Wed Oct  8 19:53:33 2003
@@ -39,7 +39,7 @@
 SQL_str         row,row1;
 char		imaf[30],imafden[30],imafsvod[30];
 FILE		*ff1,*ffden,*ffsvod;
-long		tmm;
+time_t		tmm;
 struct  tm      *bf;
 double		dbt,krt;
 double		dbtden=0.,krtden=0.;
