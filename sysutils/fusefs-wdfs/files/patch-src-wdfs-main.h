diff -u -ur ../wdfs-1.2.0-old/src/wdfs-main.h ./src/wdfs-main.h
--- ../wdfs-1.2.0-old/src/wdfs-main.h	Sat Nov  5 15:09:25 2005
+++ ./src/wdfs-main.h	Tue Jun 13 01:53:31 2006
@@ -1,6 +1,8 @@
 #ifndef WDFSMAIN_H_
 #define WDFSMAIN_H_
 
+#define FUSE_USE_VERSION 25
+
 #include <fuse.h>
 #include <ne_basic.h>
 
