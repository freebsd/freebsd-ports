--- src/support/rapi_buffer.c.orig	Sat Jan  8 06:40:07 2005
+++ src/support/rapi_buffer.c	Sat Jan  8 06:39:07 2005
@@ -498,7 +498,7 @@
   ssize_t total_size = 0;
   ssize_t result;
 
-  parts[0].iov_base = &size_le;
+  parts[0].iov_base = (char*)&size_le;
   parts[0].iov_len  = sizeof(size_le);
   total_size += parts[0].iov_len;
 

