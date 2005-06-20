Index: Output/esd/mixer.c
===================================================================
RCS file: /cvsroot/beepmp/bmp/Output/esd/mixer.c,v
retrieving revision 1.6
diff -u -r1.6 mixer.c
--- Output/esd/mixer.c	4 Dec 2004 09:29:08 -0000	1.6
+++ Output/esd/mixer.c	19 Jun 2005 08:12:02 -0000
@@ -150,7 +150,8 @@
 static void
 esdout_get_oss_volume(int *l, int *r)
 {
-    int fd, v, cmd, devs;
+    int fd, v, devs;
+    long cmd;
 
     if (esd_cfg.use_remote)
         return;
@@ -176,7 +177,8 @@
 static void
 esdout_set_oss_volume(int l, int r)
 {
-    int fd, v, cmd, devs;
+    int fd, v, devs;
+    long cmd;
 
     if (esd_cfg.use_remote)
         return;
