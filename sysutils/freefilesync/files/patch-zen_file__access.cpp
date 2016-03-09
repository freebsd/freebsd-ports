--- ../../zen/file_access.cpp.orig	2016-03-07 22:01:11.201619000 +0800
+++ ../../zen/file_access.cpp	2016-03-07 22:01:27.906454000 +0800
@@ -25,7 +25,7 @@
     #endif
 
 #elif defined ZEN_LINUX
-    #include <sys/vfs.h> //statfs
+    #include <sys/mount.h> //statfs
     #include <sys/time.h> //lutimes
     #ifdef HAVE_SELINUX
         #include <selinux/selinux.h>
