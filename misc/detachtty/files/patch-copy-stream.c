--- ./copy-stream.c.orig	2003-01-18 15:03:15.000000000 +0100
+++ ./copy-stream.c	2012-08-24 13:22:21.932915476 +0200
@@ -21,7 +21,7 @@
 
 int output_buffer(int fd) {
     int bytes_written=0,bytes_to_write=bytes_in_buf;
-    if(fd<0) return;
+    if(fd<0) return 0;
     while(bytes_to_write>0) {
 	bytes_written=write(fd,buf,bytes_to_write);
 	if(bytes_written==-1) return -1;
