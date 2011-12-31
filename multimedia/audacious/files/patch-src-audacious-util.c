--- src/audacious/util.c.orig	2011-11-08 17:37:12.000000000 +0100
+++ src/audacious/util.c	2011-11-23 20:49:18.000000000 +0100
@@ -142,9 +142,9 @@
             return NULL;
         }
 #else
-        if ((len = readlink ("/proc/self/exe", buf, size)) < 0)
+        if ((len = readlink ("/proc/curproc/file", buf, size)) < 0)
         {
-            fprintf (stderr, "Cannot access /proc/self/exe: %s.\n", strerror (errno));
+            fprintf (stderr, "Cannot access /proc/curproc/file: %s.\n", strerror (errno));
             g_free (buf);
             return NULL;
         }
