--- bgl_babylon.cc.orig	2009-05-07 14:59:58.000000000 +0400
+++ bgl_babylon.cc	2009-11-08 23:52:53.000000000 +0300
@@ -545,13 +545,8 @@
 
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
