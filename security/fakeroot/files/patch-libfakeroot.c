--- libfakeroot.c        Fri Dec 19 03:38:05 2003
+++ libfakeroot.c     Thu Mar 11 12:52:45 2004
@@ -667,6 +667,6 @@
   return 0;
 }
 
-int setgroups(size_t size, const gid_t *list){
+int setgroups(int size, const gid_t *list){
   return 0;
 }
