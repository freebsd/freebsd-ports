--- make-iso.c.orig	Mon Sep  8 21:24:07 2003
+++ make-iso.c	Thu Oct  2 21:06:43 2003
@@ -545,6 +545,7 @@
 	argv[i++] = "mkisofs";
 	argv[i++] = "-r";
 	argv[i++] = "-J";
+	argv[i++] = "-joliet-long";
 	argv[i++] = "-graft-points";
 	argv[i++] = "-path-list";
 	argv[i++] = filelist;
@@ -598,6 +599,7 @@
 	argv[i++] = "mkisofs";
 	argv[i++] = "-r";
 	argv[i++] = "-J";
+	argv[i++] = "-joliet-long";
 	argv[i++] = "-graft-points";
 	argv[i++] = "-path-list";
 	argv[i++] = filelist;
