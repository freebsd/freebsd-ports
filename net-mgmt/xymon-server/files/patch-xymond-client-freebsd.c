--- xymond/client/freebsd.c.orig	2012-11-13 07:48:19.217106974 -0600
+++ xymond/client/freebsd.c	2012-11-13 07:49:45.416552261 -0600
@@ -85,8 +85,16 @@
 	if (vmtotalstr) {
 		p = strstr(vmtotalstr, "\nFree Memory Pages:");
 		if (p) {
-			memphysfree = atol(p + 18);
+			memphysfree = atol(p + 19)/1024;
+			memphysused = memphystotal - memphysfree;
 			found++;
+		} else {
+			p = strstr(vmtotalstr, "\nFree Memory:");
+			if (p) {
+				memphysfree = atol(p + 13)/1024;
+				memphysused = memphystotal - memphysfree;
+				found++;
+			}
 		}
 	}
 
