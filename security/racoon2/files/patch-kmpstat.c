
$FreeBSD$

--- kmpstat.c.orig	Sat Aug 14 20:54:23 2004
+++ kmpstat.c	Sat Aug 14 20:54:50 2004
@@ -365,7 +365,7 @@
 	    }
 		break;
 
-	default:
+	default: break;
 		/* IGNORE */
 	}
 
