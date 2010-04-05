--- biosfont.c.orig	2008-07-28 22:31:05.000000000 +0200
+++ biosfont.c		2009-10-27 20:14:28.000000000 +0100
@@ -65,7 +65,7 @@
 			UID_ROOT,
 			GID_WHEEL,
 			S_IRUSR | S_IRGRP | S_IROTH,
-			biosfont_cdevsw.d_name);
+			"biosfont");
 		if (bootverbose)
 			printf("<biosfont>: upper=%08lx\n", fontbase);
 		break;
