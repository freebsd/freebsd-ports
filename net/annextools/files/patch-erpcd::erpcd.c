--- erpcd/erpcd.c.orig	Sat Jan 31 17:38:06 1998
+++ erpcd/erpcd.c	Thu Sep 18 20:10:32 2003
@@ -2108,11 +2108,7 @@
 {
     int savederrno = errno;
     int i,j;
-#ifdef SYS_V
     int status;
-#else
-    union wait status;
-#endif
 
 #ifdef SYS_V
     /* decrement child_count for each status successfully returned */
