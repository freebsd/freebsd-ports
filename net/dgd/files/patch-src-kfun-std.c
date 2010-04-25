--- src/kfun/std.c.orig	2010-04-25 14:29:57.000000000 -0700
+++ src/kfun/std.c	2010-04-25 14:30:09.000000000 -0700
@@ -1278,10 +1278,6 @@
 	error("open_port() in special purpose object");
     }
 
-    if (obj->flags & O_DRIVER) {
-        error("open_port() in driver object");
-    }
-
     if (f->level != 0) {
 	error("open_port() within atomic function");
     }
