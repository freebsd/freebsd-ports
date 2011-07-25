--- ariruby.c.orig	2011-04-27 21:34:36.000000000 -0400
+++ ariruby.c	2011-07-24 21:50:51.119557755 -0400
@@ -189,7 +189,7 @@
 static VALUE
 ariprint(VALUE self, VALUE outbuf)
 {
-    fprintf(stdout, "%s", RSTRING(outbuf)->ptr);
+    fprintf(stdout, "%s", RSTRING_PTR(outbuf));
 
     return self;    
 }
@@ -198,14 +198,14 @@
 arisend(VALUE self, VALUE data) 
 {
     int len;
-    len = RSTRING(data)->len;
+    len = RSTRING_LEN(data);
 
     if ((sendbuf = (char *)malloc(len + 1)) == NULL)  {
         perror("arisend malloc failed");
         close(sock);
         exit(0);
     }
-    memcpy(sendbuf, RSTRING(data)->ptr, len);
+    memcpy(sendbuf, RSTRING_PTR(data), len);
 
     if (len == 0) {
         fprintf(stderr, "please set a data in arisend function \n");
@@ -519,9 +519,6 @@
     if (sendbuf != NULL)
         free(sendbuf);
 
-    if (headbuf != NULL)
-        free(headbuf);
-
     if (nb == -1 || nb == -2) { 
 #if !(defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__APPLE__))
         alarm(0);
@@ -544,6 +541,9 @@
             exit(0);
     }
 
+    if (headbuf != NULL)
+        free(headbuf);
+
     if (sslflags)
         ssl_free(ctx, ssl);
 
