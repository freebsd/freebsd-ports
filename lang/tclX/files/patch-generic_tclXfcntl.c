--- generic/tclXfcntl.c.orig	2014-07-30 16:45:58.000000000 +0200
+++ generic/tclXfcntl.c	2014-07-30 16:46:21.000000000 +0200
@@ -162,7 +162,8 @@
     int          mode;
     int          attrib;
 {
-    int value, optValue;
+    int value = 0;
+    int optValue;
 
     switch (attrib) {
       case ATTR_RDONLY:
