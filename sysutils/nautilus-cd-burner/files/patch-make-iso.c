--- make-iso.c.orig	Fri Dec 19 13:06:34 2003
+++ make-iso.c	Mon Dec 29 16:18:15 2003
@@ -571,6 +571,7 @@
 	argv[i++] = "-r";
 	if (use_joliet) {
 		argv[i++] = "-J";
+		argv[i++] = "-joliet-long";
 	}
 	argv[i++] = "-q";
 	argv[i++] = "-graft-points";
@@ -650,6 +651,7 @@
 	argv[i++] = "-r";
 	if (use_joliet) {
 		argv[i++] = "-J";
+		argv[i++] = "-joliet-long";
 	}
 	argv[i++] = "-graft-points";
 	argv[i++] = "-path-list";
