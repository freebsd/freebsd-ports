--- buhg/smkont.c.orig	Wed Oct  8 19:53:46 2003
+++ buhg/smkont.c	Wed Oct  8 19:53:54 2003
@@ -22,7 +22,7 @@
 long		kolstr;
 SQL_str         row,row1;
 char		strsql[300];
-long		vrem;
+time_t		vrem;
 
 clear(); /*Очистить экран и закрасить фоновым цветом*/
 printw(catgets(fils,41,20,"Смена одного кода контрагента на другой во всех проводках."));
