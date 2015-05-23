--- src/kfun/std.c.orig	2011-07-30 00:30:37.000000000 -0700
+++ src/kfun/std.c	2011-07-30 00:30:49.000000000 -0700
@@ -1291,10 +1291,6 @@
 	error("open_port() in special purpose object");
     }
 
-    if (obj->flags & O_DRIVER) {
-	error("open_port() in driver object");
-    }
-
     if (f->level != 0) {
 	error("open_port() within atomic function");
     }
