--- ps.c.orig	2000-08-02 21:17:34 UTC
+++ ps.c
@@ -59,7 +59,6 @@
 #define PS(str)		OUT(psFile, str)
 #define PSU(str)	OUT(ui->psFile, str)
 #define IY(val)		(ui->height_devs - val)
-#define MAX(a, b)	((a) > (b) ? (a) : (b))
 
 /*
  * Globals
