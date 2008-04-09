--- misc.c.orig	2008-04-04 06:38:59.000000000 +0800
+++ misc.c	2008-04-07 17:48:56.000000000 +0800
@@ -290,7 +290,7 @@
 #ifdef BIG5
 			if (left[cnt] & 0x80 && left[cnt+1] != 0)
 			{
-				sprintf(temp, "%c%c", left[cnt], left[++cnt]));
+				sprintf(temp, "%c%c", left[cnt], left[++cnt]);
 			}
 			else
 			{
