--- asbutton.c.orig	1999-07-17 05:59:20.000000000 +0800
+++ asbutton.c	2007-08-03 18:13:09.000000000 +0800
@@ -605,7 +605,7 @@
 				continue;
 	  		}
 	    	if ( !strncasecmp(line, "button", 6))
-				if (atoi(&(char)line[6]) == position) 
+				if (atoi(line+6) == position) 
 					break;
 		}
 	} while (1);
