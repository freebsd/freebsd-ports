--- gregor.c.orig	Fri Jun 23 00:50:40 2000
+++ gregor.c	Thu Jun 16 17:38:02 2005
@@ -65,7 +65,7 @@
 {
     int dn;
     int i;
-    const int isleap; /* save three calls to leap() */
+    int isleap; /* save three calls to leap() */
 
     /* Some validity checks */
 
