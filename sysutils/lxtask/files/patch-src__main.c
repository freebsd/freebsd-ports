--- src/main.c.orig	2011-06-21 21:50:00 UTC
+++ src/main.c
@@ -56,7 +56,6 @@ guint win_height;
 guint refresh_interval;
 guint rID;
 
-int PAGE_SIZE;
 
 int main (int argc, char *argv[])
 {
@@ -72,7 +71,6 @@ int main (int argc, char *argv[])
 #endif
     gtk_init (&argc, &argv);
 
-    PAGE_SIZE=sysconf(_SC_PAGESIZE)>>10;
     own_uid = getuid();
 
     config_file = g_build_filename(g_get_user_config_dir(), "lxtask.conf", NULL);
