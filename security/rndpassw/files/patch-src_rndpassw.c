--- src/rndpassw.c.orig	2014-03-04 18:01:47.477094722 +0100
+++ src/rndpassw.c	2014-03-04 18:02:16.047437566 +0100
@@ -24,7 +24,7 @@
 
 int main(int argc, char **argv)
 {
-    flags_t flags = { 0 };
+    flags_t flags = { 0, 0, 0, 0 };
     int passlen = -1, passcnt = -1;
     int opt, mixlen = 0, entlen, fd;
     unsigned i, y, baselen = 0;
