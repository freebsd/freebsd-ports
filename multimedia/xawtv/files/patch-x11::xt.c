diff -ur xawtv-3.88.1/x11/xt.c xawtv-3.88.1-ma/x11/xt.c
--- x11/xt.c	Wed Apr 16 12:23:12 2003
+++ x11/xt.c	Sat Oct 11 21:04:36 2003
@@ -1459,7 +1459,7 @@
 	fprintf(stderr,"*");
 
     /* catch unix sockets on FreeBSD */
-    if (0 == length) {
+    if (0 == length || ss.ss_family == AF_UNIX) {
 	if (debug)
 	    fprintf(stderr, " ok (unix socket)\n");
 	return;
