--- common/string_util.c.orig	Wed Mar 12 23:06:14 2003
+++ common/string_util.c	Tue Apr 29 20:00:01 2003
@@ -37,6 +37,7 @@
 
 
 
+#if 0
 /*
  * Function:        strlcpy
  *
@@ -156,6 +157,7 @@
     *dst = '\0';
     return dstlen + ( src - strsource ) + strlen ( src );
 }
+#endif
 
 
 /*
