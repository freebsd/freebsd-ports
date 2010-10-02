--- ./src/main.c.orig	2010-04-12 13:54:32.000000000 +0400
+++ ./src/main.c	2010-09-25 23:50:53.951634770 +0400
@@ -51,7 +51,6 @@
 guint refresh_interval;
 guint rID;
 
-int PAGE_SIZE;
 
 int main (int argc, char *argv[])
 {
@@ -65,7 +64,6 @@
     gtk_set_locale ();
     gtk_init (&argc, &argv);
 
-    PAGE_SIZE=sysconf(_SC_PAGESIZE)>>10;
     own_uid = getuid();
 
     config_file = g_build_filename(g_get_user_config_dir(), "lxtask.conf", NULL);
