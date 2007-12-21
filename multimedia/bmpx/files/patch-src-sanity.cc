--- src/sanity.cc.orig	2007-12-21 22:12:05.000000000 +0300
+++ src/sanity.cc	2007-12-21 22:14:07.000000000 +0300
@@ -72,7 +72,7 @@
 gchar *
 sanity_check_gtk (void)
 {
-  return gtk_check_version (GTK_REQUIRED_MAJOR_VER,
+  return (gchar *)gtk_check_version (GTK_REQUIRED_MAJOR_VER,
                             GTK_REQUIRED_MINOR_VER,
                             GTK_REQUIRED_MICRO_VER);
 }
