--- chm.c.orig	Sat Jun 12 22:53:48 2004
+++ chm.c	Sat Jun 12 22:54:11 2004
@@ -165,6 +165,7 @@
 			printf("Delay: %d microseconds. \n\n",delay);
 			break;
 		default:
+			break;
 	}
 	
 	file_handle = OpenIO();
