--- shm-common.h.orig
+++ shm-common.h
@@ -20,7 +20,7 @@
 
 #define CTL_KEY 5681
 
-#ifndef __APPLE__ // should rather be #ifdef LINUX
+#if !defined(__APPLE__) && !defined(__FreeBSD__) // should rather be #ifdef LINUX
 union semun {
         int val;                  
         struct semid_ds *buf;     
