--- libparanoia/paranoia.c.orig	Sun Aug  8 13:47:31 2004
+++ libparanoia/paranoia.c	Mon Aug  9 17:19:43 2004
@@ -1481,7 +1481,7 @@
 	long		sofar;
 	long		dynoverlap = (p->dynoverlap + CD_FRAMEWORDS - 1) / CD_FRAMEWORDS;
 	long		anyflag = 0;
-	int		reduce = 0;
+static	int		reduce = 0;
 static	int		pagesize = -1;
 #define	valign(x, a)	(((char *)(x)) + ((a) - 1 - ((((UIntptr_t)(x))-1)%(a))))
 
