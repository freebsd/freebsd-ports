--- ./bgl_babylon.cc.orig	2010-12-04 00:12:46.000000000 +0300
+++ ./bgl_babylon.cc	2010-12-28 11:46:37.203723541 +0300
@@ -26,6 +26,7 @@
 #include<stdlib.h>
 #include<string.h>
 #include<stdio.h>
+#include<unistd.h>
 #include<iconv.h>
 #include <QTextDocument>
 
@@ -648,13 +648,8 @@
 
   inbufbytes = s.size();
   outbufbytes = s.size() * 6;
-#ifdef _WIN32
   const char *inbuf;
   inbuf = s.data();
-#else
-  char *inbuf;
-  inbuf = (char *)s.data();
-#endif
   outbuf = (char*)malloc( outbufbytes + 1 );
   memset( outbuf, '\0', outbufbytes + 1 );
   defbuf = outbuf;
