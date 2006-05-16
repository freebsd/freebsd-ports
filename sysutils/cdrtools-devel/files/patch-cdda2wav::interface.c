--- cdda2wav/interface.c	Mon Dec 29 11:28:09 2003
+++ cdda2wav/interface.c	Sun Jan 18 01:35:50 2004
@@ -536,7 +536,7 @@
 #endif
 	case 117:			/* pre-GEOM atapi cd */
 		if (!S_ISCHR(statstruct->st_mode)) {
-			errmsgno/EX_BAD, "%s is not a char device.\n",
+			errmsgno(EX_BAD, "%s is not a char device.\n",
 				pdev_name);
 			exit(SYNTAX_ERROR);
 		}
