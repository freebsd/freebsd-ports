--- gregor.c.orig	2000-06-22 22:50:40 UTC
+++ gregor.c
@@ -65,7 +65,7 @@ day_num(int year, int month, int day)
 {
     int dn;
     int i;
-    const int isleap; /* save three calls to leap() */
+    int isleap; /* save three calls to leap() */
 
     /* Some validity checks */
 
