--- libbuh/salorok.c.orig	Wed Oct  8 18:55:27 2003
+++ libbuh/salorok.c	Wed Oct  8 18:56:14 2003
@@ -41,8 +41,8 @@
 char            sh[10];
 FILE            *ff1,*ff2,*ff3,*ff4;
 char            imaf[20],imaf1[20],imaf2[20],imaf4[30];
-long            tmm;
-long            tmmk;
+time_t            tmm;
+time_t            tmmk;
 struct  tm      *bf;
 double          db,kr;
 double          db1,kr1;
@@ -301,7 +301,7 @@
 short mks, //0-все проводки 1-без взаимно кореспондирующих
 char *masf,double *mdo)
 {
-long            tmm;
+time_t            tmm;
 struct  tm      *bf;
 double          ddn,kkn;
 short           mvs;
@@ -604,7 +604,7 @@
 void		potf(char kor[],char nai[],short dn,short mn,short gn,
 short dk,short mk,short gk,char imaf1[],char imaf2[],char *masf,double *mdo)
 {
-long            tmm;
+time_t            tmm;
 struct  tm      *bf;
 char		imaf3[20];
 FILE		*ff1,*ff2;
