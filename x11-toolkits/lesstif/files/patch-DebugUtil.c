--- lib/Xm-2.1/DebugUtil.c.orig	Mon Mar 28 10:24:56 2005
+++ lib/Xm-2.1/DebugUtil.c	Thu Mar 31 08:45:03 2005
@@ -1162,6 +1162,7 @@
 void
 _LtDebugPrintRenderTable(char *s, XmRenderTable rt)
 {
+#ifndef LESSTIF_PRODUCTION
 	int		x;
 
 	fprintf(_LtDebugFile, "%s %p (%d renditions)\n", s, rt, rt->count);
@@ -1207,6 +1208,7 @@
 			break;
 		}
 	}
+#endif/* !LESSTIF_PRODUCTION */
 }
 
 /*
