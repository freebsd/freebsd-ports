--- main.c.orig	Wed Jul 26 15:15:28 2006
+++ main.c	Wed Nov  1 23:53:11 2006
@@ -364,7 +364,7 @@
 void sys_init(gint argc, gchar *argv[])
 {
 gchar *temp;
-const gchar *ctemp;
+const gchar *envdir, *ctemp;
 struct light_pak *light;
 FILE *fp;
 
@@ -500,7 +500,7 @@
 
 /* setup directory and file pointers */
 sysenv.cwd = g_get_current_dir();
-const gchar *envdir = g_getenv("GDIS_START_DIR");
+envdir = g_getenv("GDIS_START_DIR");
 if (envdir)
   sysenv.cwd = (gchar *) envdir;
 
@@ -510,7 +510,11 @@
 
 /* generate element file full pathname */
 /* sometimes this returns the program name, and sometimes it doesn't */
+#ifdef INSTALL
+temp = g_strdup(INSTALL);
+#else
 temp = g_find_program_in_path(argv[0]);
+#endif
 /* remove program name (if attached) */
 if (g_file_test(temp, G_FILE_TEST_IS_DIR))
   sysenv.gdis_path = temp;
