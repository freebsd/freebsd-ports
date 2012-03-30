--- ./pkg/check.c.orig	2012-03-29 23:57:58.000000000 +0200
+++ ./pkg/check.c	2012-03-30 12:27:58.010105703 +0200
@@ -313,6 +313,7 @@
 				break;
 			case 'r':
 				recomputeflatsize = true;
+				flags |= PKG_LOAD_FILES;
 				if (geteuid() != 0)
 					errx(EX_USAGE, "Needs to be root to recompute the flatsize");
 				break;
