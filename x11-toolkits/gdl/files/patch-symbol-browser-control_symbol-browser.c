--- symbol-browser-control/symbol-browser.c.orig	Fri Aug 13 20:41:15 2004
+++ symbol-browser-control/symbol-browser.c	Fri Aug 13 20:41:42 2004
@@ -28,6 +28,7 @@
 #include <gtk/gtktreeview.h>
 #include <sys/stat.h>
 #include <dirent.h>
+#include <string.h>
 
 #include <tm_project.h>
 #include <tm_tagmanager.h>
