--- dejagnu.h.orig	2009-02-27 10:06:02.041427718 +0100
+++ dejagnu.h	2009-02-27 10:06:11.829233615 +0100
@@ -136,7 +136,7 @@
     if (untest)
         printf ("\t#untested:\t\t%d\n", untest);
     if (unresolve)
-        printf ("\t#unresolved:\t\t%d\n", unresolved);
+        printf ("\t#unresolved:\t\t%d\n", unresolve);
 }
 
 #ifdef __cplusplus
