--- vfs/vfs.c.orig	Thu Dec 26 08:21:43 2002
+++ vfs/vfs.c	Tue Jun 15 03:15:09 2004
@@ -637,8 +637,7 @@
 {
     const char *cwd = mc_return_cwd();
 
-    strncpy (buffer, cwd, size - 1);
-    buffer [size - 1] = 0;
+    g_strlcpy (buffer, cwd, size);
     return buffer;
 }
 
