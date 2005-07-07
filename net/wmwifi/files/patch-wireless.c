--- src/wireless.c.orig	Sat Jul  2 14:41:48 2005
+++ src/wireless.c	Sat Jul  2 14:41:53 2005
@@ -143,6 +143,7 @@
 
 	max = get_max_ifs();
 	step = 0;
+	found = 0;
 
 	if (old > max)
 		old = max; /* just be sure to not be out of bounds */
