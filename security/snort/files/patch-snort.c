--- src/snort.c.orig	Thu Apr 17 14:39:59 2003
+++ src/snort.c	Thu Apr 17 14:40:09 2003
@@ -1729,7 +1729,7 @@
 {
     struct stat st;
     int i;
-    char *conf_files[]={"/etc/snort.conf", "./snort.conf", NULL};
+    char *conf_files[]={"%%PREFIX%%/etc/snort.conf", "./snort.conf", NULL};
     char *fname = NULL;
     char *home_dir = NULL;
     char *rval = NULL;
