--- src/chkshsgr.c.orig	2018-03-05 09:33:03 UTC
+++ src/chkshsgr.c
@@ -4,7 +4,7 @@
 
 int main()
 {
-  short x[4];
+  gid_t x[4];
 
   x[0] = x[1] = 0;
   if (getgroups(1,x) == 0) if (setgroups(1,x) == -1) _exit(1);
