--- ProcessList.c.orig	2009-03-21 23:21:46.000000000 +0800
+++ ProcessList.c	2009-03-21 23:22:04.000000000 +0800
@@ -563,9 +563,8 @@
                process->pid = pid;
             }
          }
-         if (parent) {
-            process->tgid = parent->pid;
-         }
+
+	 process->tgid = parent ? parent->pid : pid;
 
          if (showUserlandThreads && (!parent || pid != parent->pid)) {
             char subdirname[MAX_NAME+1];
