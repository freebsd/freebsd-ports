--- buhg/xmu.c.orig	Wed Oct  8 19:55:16 2003
+++ buhg/xmu.c	Wed Oct  8 19:55:22 2003
@@ -53,7 +53,7 @@
 {
 struct  passwd  *ktor; /*Кто работает*/
 struct  tm      *bf;
-long            tmm;
+time_t            tmm;
 SQL_str   	row;
 short		kom,kom1;
 short		i;
