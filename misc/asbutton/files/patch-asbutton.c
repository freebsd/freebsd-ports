
$FreeBSD$

--- asbutton.c.orig
+++ asbutton.c
@@ -605,7 +605,7 @@
 				continue;
 	  		}
 	    	if ( !strncasecmp(line, "button", 6))
-				if (atoi(&(char)line[6]) == position) 
+				if (atoi((char)line[6]) == position) 
 					break;
 		}
 	} while (1);
