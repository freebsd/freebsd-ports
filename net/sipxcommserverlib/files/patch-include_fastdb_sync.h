--- ./include/fastdb/sync.h.orig	Thu Dec 28 18:42:54 2006
+++ ./include/fastdb/sync.h	Thu Dec 28 18:47:03 2006
@@ -613,7 +613,7 @@
 
     // for Linux: Temporary addition to aid debugging
     int getTid() {
-       return tid;
+       return (int)tid;
     }
 
     int getPid() {
