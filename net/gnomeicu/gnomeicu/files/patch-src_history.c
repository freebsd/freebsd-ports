--- src/history.c.orig	Mon Nov 29 20:48:25 2004
+++ src/history.c	Mon Nov 29 20:21:37 2004
@@ -214,6 +214,11 @@
     char direction;
     time_t time;
 
+    if (! (ptr+4)) {
+      g_free (hp->buffer);
+      g_free (hp);
+      return FALSE;
+    }
     /* read header info */
     sscanf (ptr+4, "%c %d", &direction, (int *)&time);

