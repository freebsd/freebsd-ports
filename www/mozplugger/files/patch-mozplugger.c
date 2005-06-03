--- mozplugger.c.orig	Sun Apr 17 05:19:59 2005
+++ mozplugger.c	Fri Jun  3 20:55:32 2005
@@ -568,6 +568,9 @@
 	  if (cb(fname, data)) return 1;
      }
 
+     snprintf(fname, sizeof(fname), PREFIX "/etc/%s", basename);
+     if (cb(fname, data)) return 1;
+
      snprintf(fname, sizeof(fname), "/etc/%s", basename);
      if (cb(fname, data)) return 1;
 
@@ -1208,6 +1211,8 @@
  *****************************************************************************/
 NPError NPP_SetWindow(NPP instance, NPWindow* window)
 {
+     XSetWindowAttributes attrib;
+
      D("SetWindow\n");
 
      if (!instance)
@@ -1239,7 +1244,6 @@
 	  D("Writing WIN 0x%x to fd %d\n", window->window, THIS->fd);
 	  write(THIS->fd, (char *)window, sizeof(*window));
 
-	  XSetWindowAttributes attrib;
 	  attrib.override_redirect = True;
 	  XChangeWindowAttributes(THIS->display, (Window)THIS->windata.window,
 				  CWOverrideRedirect, &attrib);
