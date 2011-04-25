--- src/audacious/util.c.orig	2011-04-23 14:49:07.000000000 +0200
+++ src/audacious/util.c	2011-04-23 14:50:08.000000000 +0200
@@ -174,9 +174,9 @@
         return NULL;
     }
 #else
-    if ((len = readlink ("/proc/self/exe", buf, sizeof buf)) < 0)
+    if ((len = readlink ("/proc/curproc/file", buf, sizeof buf)) < 0)
     {
-        fprintf (stderr, "Cannot access /proc/self/exe: %s.\n", strerror (errno));
+        fprintf (stderr, "Cannot access /proc/curproc/file: %s.\n", strerror (errno));
         return NULL;
     }
 #endif
