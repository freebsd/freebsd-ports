--- read_data.c.orig	Wed Jul  7 17:00:30 2004
+++ read_data.c	Sun Jul 25 23:36:58 2004
@@ -32,7 +32,7 @@
     if (sizeof(start) < 8)
       start = atol(argv[2]);
     else
-      start = atoll(argv[2]);
+      start = strtoll(argv[2], (char **)NULL, 10);
     bytes = atol(argv[3]);
 
     if ((bytes < 1) || (bytes > MAX_SIZE)) {
