--- ./libpkg/pkg_ports.c.orig	2012-03-31 23:46:19.121855756 +0200
+++ ./libpkg/pkg_ports.c	2012-03-31 23:46:24.356886561 +0200
@@ -726,6 +726,8 @@
 	for (i = 0; i <= nbel; i++) {
 		if (pplist.ignore_next) {
 			pplist.ignore_next = false;
+			plist_p += next + 1;
+			next = strlen(plist_p);
 			continue;
 		}
 
