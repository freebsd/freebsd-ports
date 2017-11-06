--- common/vncauth.c.orig	2017-07-05 07:43:58 UTC
+++ common/vncauth.c
@@ -42,6 +42,10 @@
 #include <sys/stat.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <fcntl.h>
+#endif
+
 #include <time.h>
 
 #ifdef WIN32
@@ -196,6 +200,8 @@ rfbEncryptBytes(unsigned char *bytes, char *passwd)
 	rfbDes(bytes+i, bytes+i);
     }
 }
+
+void rfbEncryptBytes2(unsigned char *, const int, unsigned char *);
 
 void
 rfbEncryptBytes2(unsigned char *where, const int length, unsigned char *key) {
