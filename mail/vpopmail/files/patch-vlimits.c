--- vlimits.c.old	Fri Feb 14 14:44:38 2003
+++ vlimits.c	Fri Feb 14 14:45:21 2003
@@ -46,7 +46,7 @@
 
     /* get filename */
     vget_assign(mydomain, dir, sizeof(dir), &uid, &gid);
-    strncat(dir, "/.qmailadmin-limits", sizeof(dir));
+    strncat(dir, "/.qmailadmin-limits", sizeof(dir) - strlen(dir) - 1);
 
     /* open file */
     if ((fs = fopen(dir, "r")) != NULL) {
@@ -209,7 +209,7 @@
 
     /* get filename */
     vget_assign(mydomain, dir, sizeof(dir), &uid, &gid);
-    strncat(dir, "/.qmailadmin-limits", sizeof(dir));
+    strncat(dir, "/.qmailadmin-limits", sizeof(dir) - strlen(dir) - 1);
 
     /* open file */
     if ((fs = fopen(dir, "w+")) != NULL) {
@@ -265,7 +265,7 @@
 
     /* get filename */
     vget_assign(mydomain, dir, sizeof(dir), &uid, &gid);
-    strncat(dir, "/.qmailadmin-limits", sizeof(dir));
+    strncat(dir, "/.qmailadmin-limits", sizeof(dir) - strlen(dir) - 1);
     return unlink(dir);
 }
 
