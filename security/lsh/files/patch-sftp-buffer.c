--- src/sftp/buffer.c.orig	Sun Feb 23 19:34:44 2003
+++ src/sftp/buffer.c	Sun Mar  2 09:52:24 2003
@@ -227,7 +227,7 @@
 {
   uint8_t buf[8];
 
-  WRITE_uint64_t(buf, value);
+  WRITE_UINT64(buf, value);
   PUT_DATA(o, buf);
 }
 
