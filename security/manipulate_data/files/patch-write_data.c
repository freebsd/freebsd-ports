--- write_data.c.orig	Wed Jul  7 16:58:54 2004
+++ write_data.c	Sun Jul 25 23:37:48 2004
@@ -49,7 +49,7 @@
     if (sizeof(start) < 8)
       start = atol(c_ptr2);
     else
-      start = atoll(c_ptr2);
+      start = strtoll(c_ptr2, (char **)NULL, 10);
     bytes = atol(c_ptr);
     if (sizeof(start) < 8)
       sprintf(tmpbuf, "%lu.%lu", (unsigned long) start, bytes);
