--- atopsar.c.orig	2014-01-16 00:05:34 UTC
+++ atopsar.c
@@ -600,7 +600,8 @@
 		*/
 		printf("%s  ", convtime(curtime, timebuf));
 	
-		if ( !(rv = (pridef[i].priline)(ss, (struct tstat *)0, 0,
+		if ( !(rv = (pridef[i].priline)(ss, (struct tstat *)0,
+					(struct tstat **)0, 0,
 					numsecs, numsecs*hertz, hertz,
 					osvers, osrel, ossub, 
 		                        stampalways ? timebuf : "        ",
