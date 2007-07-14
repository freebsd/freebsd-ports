--- src/udmutils.c.orig	2007-07-14 12:51:12.000000000 +0200
+++ src/udmutils.c	2007-07-14 12:51:29.000000000 +0200
@@ -724,7 +724,7 @@
 		tmp[i++]='0';
 	else while (num != 0){
 		tmp[i++] = digits[(unsigned long) num % (unsigned) base];
-                (unsigned long) num /= (unsigned) base;
+                num /= (unsigned) base;
              }
 	if (i > precision)
 		precision = i;
