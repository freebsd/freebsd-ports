
$FreeBSD$

--- src/sg_project_menu.c	2001/07/04 14:27:49	1.1
+++ src/sg_project_menu.c	2001/07/04 14:28:27
@@ -554,9 +554,9 @@
  }
 
  if ( getenv("SG_ROOT") )
-    g_snprintf(path, 250, "%s/share/scigraphica/examples/%s", getenv("SG_ROOT"), (gchar*)data);
+    g_snprintf(path, 250, "%s/share/gnome/scigraphica/examples/%s", getenv("SG_ROOT"), (gchar*)data);
  else
-    g_snprintf(path, 250, SG_ROOT "/share/scigraphica/examples/%s", (gchar*)data);
+    g_snprintf(path, 250, SG_ROOT "/share/gnome/scigraphica/examples/%s", (gchar*)data);
 
  sg_project_close();
  sg_project_new();
