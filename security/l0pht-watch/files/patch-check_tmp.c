--- check_tmp.c.orig	1999-09-24 20:33:35 UTC
+++ check_tmp.c
@@ -2,6 +2,8 @@
    directories. Ostensibly to start hammering on how bad people are on
    tmp droppings following links, etc. etc. .mudge 8.20.98 */
 
+#include <string.h>
+
 #include "check_tmp.h"
 
 void usage(char *progname);
@@ -14,6 +16,7 @@ int checkdir(char *);
 void walklist(struct listStruct *);
 #endif
 int become_daemon(void);
+int syslogflag;
 
 int main(int argc, char **argv){
 
@@ -37,8 +40,14 @@ int main(int argc, char **argv){
   char error_buffer[256];
 #endif
 #endif
-  
 
+#if (__FreeBSD_version >= 500011) || (__FreeBSD_version >= 410000 && __FreeBSD_version < 500000)
+  struct kevent ev;
+  int fd;
+  struct timespec ts = { 0, 0 };
+  int kq = -1;
+#endif
+
   struct listStruct *list = NULL;
 
   syslogflag=0; /* initialize */
@@ -178,6 +187,21 @@ int main(int argc, char **argv){
     exit(1);
   }
 
+#if (__FreeBSD_version >= 500011) || (__FreeBSD_version >= 410000 && __FreeBSD_version < 500000)
+  /* Set up the KQ on the target directory */
+  fd = dirfd(dirp);
+
+  kq = kqueue();
+  if (kq < 0)
+    err(1, "kqueue");
+
+  ev.ident = fd;
+  ev.filter = EVFILT_VNODE;
+  ev.flags = EV_ADD | EV_ENABLE | EV_CLEAR;
+  ev.fflags = NOTE_WRITE;
+  kevent(kq, &ev, 1, NULL, 0, &ts);
+#endif
+
   /* steup the first element of the list */
   while ((dp = readdir(dirp)) != NULL){
     if (!list) /* first time */
@@ -266,6 +290,10 @@ int main(int argc, char **argv){
   rewinddir(dirp);
 
   while (1){
+
+#if (__FreeBSD_version >= 500011) || (__FreeBSD_version >= 410000 && __FreeBSD_version < 500000)
+    if (ev.fflags & NOTE_WRITE) {
+#endif
     while ((dp = readdir(dirp)) != NULL){
       if (!(checknode(list, watchdir, dp->d_name))){
         if (replacewatchflag){
@@ -352,11 +380,22 @@ int main(int argc, char **argv){
       /* closedir(dirp); */
       }
     }
-#ifdef 0
+#if 0
     walklist(list);
 #endif
     list = prunelist(list); 
     rewinddir(dirp);
+
+#if (__FreeBSD_version >= 500011) || (__FreeBSD_version >= 410000 && __FreeBSD_version < 500000)
+    /* Reset event so we don't trigger on the rewinddir */
+    kevent(kq, &ev, 1, NULL, 0, &ts);
+
+    /* Block until the directory changes */
+    if (kevent(kq, NULL, 0, &ev, 1, NULL) < 0)
+      err(1, "kevent");
+
+  }
+#endif
   }
 /*   closedir(dirp); */
 
