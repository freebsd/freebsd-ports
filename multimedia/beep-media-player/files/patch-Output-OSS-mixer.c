Index: Output/OSS/mixer.c
===================================================================
RCS file: /cvsroot/beepmp/bmp/Output/OSS/mixer.c,v
retrieving revision 1.6
diff -u -r1.6 mixer.c
--- Output/OSS/mixer.c	4 Dec 2004 09:29:08 -0000	1.6
+++ Output/OSS/mixer.c	19 Jun 2005 08:11:45 -0000
@@ -50,7 +50,8 @@
 void
 oss_get_volume(int *l, int *r)
 {
-    int fd, v, cmd, devs;
+    int fd, v, devs;
+    long cmd;
     gchar *devname;
 
     devname = get_mixer_device();
@@ -81,7 +82,8 @@
 void
 oss_set_volume(int l, int r)
 {
-    int fd, v, cmd, devs;
+    int fd, v, devs;
+    long cmd;
     gchar *devname;
 
     devname = get_mixer_device();
