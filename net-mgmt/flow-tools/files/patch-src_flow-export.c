--- src/flow-export.c.orig	Tue Jul 10 17:59:28 2007
+++ src/flow-export.c	Tue Jul 10 18:00:22 2007
@@ -961,7 +961,7 @@
 
 int fmt_xfields_type(char *buf, u_int64 xfield)
 {
-  int comma;
+  int comma = 0;
 
   buf[0] = 0;
 
