--- netmap/misc.c.orig	Sun Dec 15 14:54:26 2002
+++ netmap/misc.c	Sun Dec 15 14:54:26 2002
@@ -54,7 +54,7 @@
 	return false;
     
     bool had_point = false;
-    int beyond_point = 0;
+    unsigned int beyond_point = 0;
 
     int int_first = 0;
     for(unsigned i = 0; i < str.length(); i++) {
