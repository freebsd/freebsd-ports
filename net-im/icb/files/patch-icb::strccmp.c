--- icb/strccmp.c.orig	Sat Jun 12 23:08:33 2004
+++ icb/strccmp.c	Sat Jun 12 23:23:48 2004
@@ -237,7 +237,7 @@
 				if (a == '\0')
 					return 0;
 
-shloop:	    }
+shloop:;	    }
 			while (cm[a] != cm[b]);
 
 
