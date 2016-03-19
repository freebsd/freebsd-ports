--- write_data.c.orig	2004-07-07 14:58:54 UTC
+++ write_data.c
@@ -49,7 +49,7 @@ int main (int argc, char *argv[]) {
     if (sizeof(start) < 8)
       start = atol(c_ptr2);
     else
-      start = atoll(c_ptr2);
+      start = strtoll(c_ptr2, (char **)NULL, 10);
     bytes = atol(c_ptr);
     if (sizeof(start) < 8)
       sprintf(tmpbuf, "%lu.%lu", (unsigned long) start, bytes);
