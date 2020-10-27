--- src/main.c.orig	2019-01-13 19:41:23 UTC
+++ src/main.c
@@ -57,8 +57,6 @@ gint win_height;
 gint refresh_interval;
 guint rID;
 
-int page_size;
-
 int main (int argc, char *argv[])
 {
 
@@ -73,7 +71,6 @@ int main (int argc, char *argv[])
 #endif
     gtk_init (&argc, &argv);
 
-    page_size=sysconf(_SC_PAGESIZE)>>10;
     own_uid = getuid();
 
     config_file = g_build_filename(g_get_user_config_dir(), "lxtask.conf", NULL);
