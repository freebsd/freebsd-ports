--- lib/Pz/MvFunction.cc.orig	2013-06-16 10:37:30.000000000 +0900
+++ lib/Pz/MvFunction.cc	2013-06-16 10:38:07.000000000 +0900
@@ -352,9 +352,9 @@
 	uint32_t d = 0;
 
 	for(d = 0; d < buflen; d ++) {
-		if((buf[d] < '0') || (buf[d] > '9') &&
-		   (buf[d] < 'A') || (buf[d] > 'F') &&
-		   (buf[d] < 'a') || (buf[d] > 'f')) {
+		if(((buf[d] < '0') || (buf[d] > '9')) &&
+		   ((buf[d] < 'A') || (buf[d] > 'F')) &&
+		   ((buf[d] < 'a') || (buf[d] > 'f'))) {
 			return false;
 		}
 	}
