--- src/snort.c.orig	Sun Oct  6 02:14:32 2002
+++ src/snort.c	Sun Oct  6 02:14:18 2002
@@ -2193,7 +2193,7 @@
     struct stat st;
     int found;
     int i;
-    char *conf_files[]={"/etc/snort.conf", "./snort.conf", NULL};
+    char *conf_files[]={"%%PREFIX%%/etc/snort.conf", "./snort.conf", NULL};
     char *fname = NULL;
     char *home_dir;
     char *tmp;
