--- sendout.c.orig	2022-01-26 14:24:22.000017000 -0800
+++ sendout.c	2022-01-26 14:25:03.262517000 -0800
@@ -885,6 +885,7 @@
 				cp = expand(cp);
 			else
 				cp = SENDMAIL;
+			args[0] = cp;
 			execv(cp, args);
 			perror(cp);
 		}
