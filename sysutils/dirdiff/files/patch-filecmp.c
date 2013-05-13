--- filecmp.c.orig	2005-04-19 12:22:01.000000000 +0200
+++ filecmp.c	2013-05-13 17:00:44.000000000 +0200
@@ -9,6 +9,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
+#include <unistd.h>
 #include <tcl.h>
 #include <sys/fcntl.h>
 
@@ -125,7 +126,7 @@
 	p2 += i;
 	k2 -= i;
 	/* 4 == strlen("<dollar>Id<dollar>") */
-	if (k1 < 4 && !e1 || k2 < 4 && !e2)
+	if ((k1 < 4 && !e1) || (k2 < 4 && !e2))
 	    break;
 	if (k1 < 4 || k2 < 4) {
 	    /* near the end of one or both files */
@@ -195,7 +196,7 @@
 		k2 -= i;
 		if (match < BKTAGLEN) {
 			/* we have run out of one or other buffer */
-			if (k1 == 0 && e1 || k2 == 0 && e2) {
+			if ((k1 == 0 && e1) ||( k2 == 0 && e2)) {
 				if (k1 == k2)
 					break;
 				return 0;
@@ -219,7 +220,7 @@
 			continue;
 		}
 		/* ran out before eol on one or both files */
-		if (t1 == k1 && e1 || t2 == k2 && e2) {
+		if ((t1 == k1 && e1) || (t2 == k2 && e2)) {
 			k1 -= t1;
 			k2 -= t2;
 			if (k1 == k2)
@@ -341,7 +342,7 @@
     if (n1 < 0 || n2 < 0)
 	return TCL_ERROR;
 
-    sprintf(interp->result, "%d", same);
+    Tcl_SetObjResult(interp, Tcl_NewIntObj(same));
     return TCL_OK;
 }
 
