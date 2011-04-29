--- ariruby.c.orig	Fri Apr 29 09:23:11 2011
+++ ariruby.c	Fri Apr 29 09:24:14 2011
@@ -519,9 +519,6 @@
     if (sendbuf != NULL)
         free(sendbuf);
 
-    if (headbuf != NULL)
-        free(headbuf);
-
     if (nb == -1 || nb == -2) { 
 #if !(defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__APPLE__))
         alarm(0);
@@ -543,6 +540,9 @@
         if (!pflags)
             exit(0);
     }
+
+    if (headbuf != NULL)
+        free(headbuf);
 
     if (sslflags)
         ssl_free(ctx, ssl);
