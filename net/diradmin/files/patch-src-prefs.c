--- src/prefs.c.orig	Thu Jun 12 15:03:12 2003
+++ src/prefs.c	Thu Jan 22 10:16:30 2004
@@ -34,6 +34,7 @@
   gchar *homedir = NULL;
   gchar *cfgfile = NULL;
   connection_profile *connprof = NULL;
+  gint tls;
 
   gboolean is_default;
 
@@ -53,7 +54,6 @@
   preferences.logindefaults.VUID_MAX = 60000;
   preferences.logindefaults.VGID_MIN = 500;
   preferences.logindefaults.VGID_MAX = 60000;
-  gint tls;
 
 
 
