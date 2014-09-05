--- src/rndpassw.c.orig	2014-03-02 18:22:27.000000000 -0500
+++ src/rndpassw.c	2014-08-30 13:24:58.742060993 -0400
@@ -24,7 +24,7 @@
 
 int main(int argc, char **argv)
 {
-    flags_t flags = { 0 };
+    flags_t flags = { 0, 0, 0, 0 };
     int passlen = -1, passcnt = -1;
     int opt, mixlen = 0, entlen, fd;
     unsigned i, y, baselen = 0;
@@ -133,7 +133,7 @@
 
     entoff = entbuf = malloc(entlen);
     if(entbuf == NULL) {
-        fprintf(stderr, "Could not allocate %zd bytes\n", entlen);
+        fprintf(stderr, "Could not allocate %zd bytes\n", (size_t)entlen);
         return (1);
     }
 
@@ -148,7 +148,7 @@
     /* create and fill dictionary */
     mixbuf = malloc(mixlen);
     if(mixbuf == NULL) {
-        fprintf(stderr, "Could not allocate %zd bytes of memory\n", mixlen);
+        fprintf(stderr, "Could not allocate %zd bytes of memory\n", (size_t)mixlen);
         return (1);
     }
 
