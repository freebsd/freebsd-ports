--- src/output.c.orig	2010-07-27 07:31:03 UTC
+++ src/output.c
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
