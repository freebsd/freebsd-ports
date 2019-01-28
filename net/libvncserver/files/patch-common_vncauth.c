--- common/vncauth.c.orig	2019-01-06 19:09:30 UTC
+++ common/vncauth.c
@@ -44,6 +44,10 @@
 #include <sys/stat.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <fcntl.h>
+#endif
+
 #include <time.h>
 
 #ifdef WIN32
@@ -198,6 +202,8 @@ rfbEncryptBytes(unsigned char *bytes, char *passwd)
 	rfbDes(bytes+i, bytes+i);
     }
 }
+
+void rfbEncryptBytes2(unsigned char *, const int, unsigned char *);
 
 void
 rfbEncryptBytes2(unsigned char *where, const int length, unsigned char *key) {
