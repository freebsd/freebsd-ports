--- mozplugger.c.orig	Mon Aug 29 14:08:04 2005
+++ mozplugger.c	Fri Jan 27 17:04:36 2006
@@ -572,6 +572,9 @@
 	  if (cb(fname, data)) return 1;
      }
 
+     snprintf(fname, sizeof(fname), PREFIX "/etc/%s", basename);
+     if (cb(fname, data)) return 1;
+
      snprintf(fname, sizeof(fname), "/etc/%s", basename);
      if (cb(fname, data)) return 1;
 
