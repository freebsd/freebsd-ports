--- ./libemc2_1.c.orig	2010-08-31 08:37:40.000000000 -0400
+++ ./libemc2_1.c	2010-08-31 08:38:38.000000000 -0400
@@ -1517,7 +1517,7 @@
 	i__1[2] = 7, a__1[2] = "' retry";
 	s_cat(ch__1, a__1, i__1, &c__3, 99L);
 	scrtch_(ch__1, ii + 19);
-/*       call scrtch('mauvais type : '''/*type(1:ii)//''' recommencez'*/
+/*       call scrtch('mauvais type : '''/*type(1:ii)//''' recommencez'
 ) #FR*/
 	goto L5;
     }
