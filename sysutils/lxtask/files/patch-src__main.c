--- src/main.c.orig	2019-01-13 11:41:23.000000000 -0800
+++ src/main.c	2020-10-21 12:50:26.931353000 -0700
@@ -57,8 +57,6 @@
 gint refresh_interval;
 guint rID;
 
-int page_size;
-
 int main (int argc, char *argv[])
 {
 
@@ -73,7 +71,6 @@
 #endif
     gtk_init (&argc, &argv);
 
-    page_size=sysconf(_SC_PAGESIZE)>>10;
     own_uid = getuid();
 
     config_file = g_build_filename(g_get_user_config_dir(), "lxtask.conf", NULL);
