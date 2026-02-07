--- and.c.orig	Mon Apr  5 23:19:01 2004
+++ and.c	Thu Oct  6 16:04:09 2005
@@ -47,7 +47,11 @@
 #include <sys/types.h>
 #include <signal.h>
 #include <regex.h>
-#include <values.h>
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500014
+#include <sys/limits.h>
+#else
+#include <limits.h>
+#endif
 
 #define DEBUG 0
 
@@ -714,7 +718,7 @@
     } else if (and_db.entry[i].uid == -1) {
       exactness[i] = 0;
     } else {
-      exactness[i] = -MAXINT;
+      exactness[i] = -INT_MAX;
     }
     /* group id */
     if (gid == and_db.entry[i].gid) {
@@ -722,7 +726,7 @@
     } else if (and_db.entry[i].gid == -1) {
       exactness[i] += 0;
     } else {
-      exactness[i] = -MAXINT;
+      exactness[i] = -INT_MAX;
     }
     /* command */
     if (command!=NULL && regexec(and_db.entry[i].command,command,0,0,0) == 0) {
@@ -730,7 +734,7 @@
     } else if (strcmp(and_db.entry[i].command_str,"*") == 0) {
       exactness[i] += 0;
     } else {
-      exactness[i] = -MAXINT;
+      exactness[i] = -INT_MAX;
     }
     /* parent */
     par = parent;
@@ -745,7 +749,7 @@
         exactness[i] += 0;
         break;
       } else if (last) {
-        exactness[i] = -MAXINT;
+        exactness[i] = -INT_MAX;
         break;
       }
       par = par->parent;
