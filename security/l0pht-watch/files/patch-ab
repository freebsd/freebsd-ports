--- check_tmp.c.orig	Fri Sep 24 15:33:35 1999
+++ check_tmp.c	Tue Jul 18 16:18:59 2000
@@ -37,7 +37,13 @@
   char error_buffer[256];
 #endif
 #endif
-  
+
+#if (__FreeBSD_version >= 500011) || (__FreeBSD_version >= 410000 && __FreeBSD_version < 500000)
+  struct kevent ev;
+  int fd;
+  struct timespec ts = { 0, 0 };
+  int kq = -1;
+#endif
 
   struct listStruct *list = NULL;
 
@@ -178,6 +184,21 @@
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
@@ -266,6 +287,10 @@
   rewinddir(dirp);
 
   while (1){
+
+#if (__FreeBSD_version >= 500011) || (__FreeBSD_version >= 410000 && __FreeBSD_version < 500000)
+    if (ev.fflags & NOTE_WRITE) {
+#endif
     while ((dp = readdir(dirp)) != NULL){
       if (!(checknode(list, watchdir, dp->d_name))){
         if (replacewatchflag){
@@ -352,11 +377,22 @@
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
 
