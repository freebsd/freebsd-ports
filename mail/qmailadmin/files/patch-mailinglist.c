--- mailinglist.c~	2009-03-09 10:35:01.000000000 +0900
+++ mailinglist.c	2013-03-25 23:48:29.000000000 +0900
@@ -681,13 +681,15 @@
     dup2(handles[1],fileno(stdout));
     sprintf(TmpBuf1, "%s/ezmlm-list", EZMLMDIR);
     if(mod == 1) {
-        sprintf(TmpBuf2, "%s/%s/mod", RealDir, ActionUser);
+        sprintf(TmpBuf2, "%s/%s", RealDir, ActionUser);
+        execl(TmpBuf1, "ezmlm-list", TmpBuf2, "mod", NULL);
     } else if(mod == 2) {
-        sprintf(TmpBuf2, "%s/%s/digest", RealDir, ActionUser);
+        sprintf(TmpBuf2, "%s/%s", RealDir, ActionUser);
+        execl(TmpBuf1, "ezmlm-list", TmpBuf2, "digest", NULL);
     } else {
         sprintf(TmpBuf2, "%s/%s/", RealDir, ActionUser);
+        execl(TmpBuf1, "ezmlm-list", TmpBuf2, NULL);
     }
-    execl(TmpBuf1, "ezmlm-list", TmpBuf2, NULL);
     exit(127);
   } else {
     close(handles[1]);
@@ -799,9 +801,9 @@
   pid=fork();
   if (pid==0) {
     snprintf(subpath, sizeof(subpath), "%s/ezmlm-sub", EZMLMDIR);
-    snprintf(listpath, sizeof(listpath), "%s/%s/%s",
-      RealDir, ActionUser, dir);
-    execl(subpath, "ezmlm-sub", listpath, email, NULL);
+    snprintf(listpath, sizeof(listpath), "%s/%s",
+      RealDir, ActionUser);
+    execl(subpath, "ezmlm-sub", listpath, dir, email, NULL);
     exit(127);
   } else wait(&pid);
