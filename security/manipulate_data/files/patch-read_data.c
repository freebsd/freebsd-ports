--- read_data.c.orig	2004-07-07 15:00:30 UTC
+++ read_data.c
@@ -32,7 +32,7 @@ int main (int argc, char *argv[]) {
     if (sizeof(start) < 8)
       start = atol(argv[2]);
     else
-      start = atoll(argv[2]);
+      start = strtoll(argv[2], (char **)NULL, 10);
     bytes = atol(argv[3]);
 
     if ((bytes < 1) || (bytes > MAX_SIZE)) {
