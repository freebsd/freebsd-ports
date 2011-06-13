--- src/output.c.orig	2011-05-30 16:52:55.000000000 -0400
+++ src/output.c	2011-05-30 16:53:21.000000000 -0400
@@ -22,11 +22,6 @@
 #ifdef SDIG_USE_SEMS
 
 enum ops { UNLOCK = (int)1, LOCK = (int)(-1) };
-union semun {
-    int val;
-    struct semid_ds *buf;
-    ushort *array;
-};
 
 int lock = 0;
 // int pad = 0;
