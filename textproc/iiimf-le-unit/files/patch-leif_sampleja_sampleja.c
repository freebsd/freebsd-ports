--- leif/sampleja/sampleja.c	Fri Mar 16 00:52:22 2001
+++ leif/sampleja/sampleja.c	Wed Feb 16 20:42:34 2005
@@ -331,7 +331,7 @@
 #ifdef	WIN32
     l->path = "d:\\sampleja_obj.jar";		/* path */
 #else
-    l->path = "/usr/lib/im/locale/ja/sampleja/sampleja_obj.jar";	/* path */
+    l->path = IMDIR "/locale/ja/sampleja/sampleja_obj.jar";	/* path */
 #endif
     l->signature = "";
     l->class_names = class_names;
