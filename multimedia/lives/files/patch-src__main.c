--- ./src/main.c.orig	Fri Jan 26 12:50:12 2007
+++ ./src/main.c	Fri Jan 26 12:50:23 2007
@@ -91,6 +91,7 @@
   capable=get_capabilities();
 
   palette=(_palette*)(g_malloc(sizeof(_palette)));
+  mainw->cached_list=NULL;
 
   if (!capable->smog_version_correct||!capable->can_write_to_tempdir) {
     g_snprintf(prefs->theme,64,"none");
@@ -98,7 +99,6 @@
   else {
     // from here onwards we can use get_pref() and friends  //////
     gchar *rcfile=g_strdup_printf("%s/.lives",capable->home_dir);
-    mainw->cached_list=NULL;
     cache_file_contents(rcfile);
     g_free(rcfile);
 
