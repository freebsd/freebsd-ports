--- vlimits.c.orig	Sat Nov  2 22:39:03 2002
+++ vlimits.c	Sat Nov  2 22:41:10 2002
@@ -49,7 +49,7 @@
 
     /* get filename */
     vget_assign(domain, dir, sizeof(dir), &uid, &gid);
-    strncat(dir, "/.qmailadmin-limits", sizeof(dir));
+    strncat(dir, "/.qmailadmin-limits", sizeof(dir) - strlen(dir) - 1);
 
     /* open file */
     if ((fs = fopen(dir, "r")) != NULL) {
@@ -143,7 +143,7 @@
 
     /* get filename */
     vget_assign(domain, dir, sizeof(dir), &uid, &gid);
-    strncat(dir, "/.qmailadmin-limits", sizeof(dir));
+    strncat(dir, "/.qmailadmin-limits", sizeof(dir) - strlen(dir) - 1);
 
     /* open file */
     if ((fs = fopen(dir, "w+")) != NULL) {
@@ -183,7 +183,7 @@
 
     /* get filename */
     vget_assign(domain, dir, sizeof(dir), &uid, &gid);
-    strncat(dir, "/.qmailadmin-limits", sizeof(dir));
+    strncat(dir, "/.qmailadmin-limits", sizeof(dir) - strlen(dir) - 1);
     return unlink(dir);
 }
 
