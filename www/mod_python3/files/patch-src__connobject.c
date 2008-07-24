Index: files/patch-src__connobject.c
===================================================================
RCS file: files/patch-src__connobject.c
diff -N files/patch-src__connobject.c
--- /dev/null	1 Jan 1970 00:00:00 -0000
+++ files/patch-src__connobject.c	10 Jul 2008 20:08:25 -0000
@@ -0,0 +1,11 @@
+--- ./src/connobject.c.orig	2008-07-10 19:57:53.000000000 +0000
++++ ./src/connobject.c	2008-07-10 19:57:18.000000000 +0000
+@@ -139,7 +139,7 @@
+     bytes_read = 0;
+ 
+     while ((bytes_read < len || len == 0) &&
+-           !(b == APR_BRIGADE_SENTINEL(b) ||
++           !(b == APR_BRIGADE_SENTINEL(bb) ||
+              APR_BUCKET_IS_EOS(b) || APR_BUCKET_IS_FLUSH(b))) {
+ 
+         const char *data;
