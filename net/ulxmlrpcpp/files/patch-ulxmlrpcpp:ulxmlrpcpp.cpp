--- ulxmlrpcpp/ulxmlrpcpp.cpp.orig	Thu Nov 27 02:44:22 2003
+++ ulxmlrpcpp/ulxmlrpcpp.cpp	Wed Dec 10 11:34:49 2003
@@ -742,7 +742,7 @@
   {
     size_t outbytes = sizeof(buffer);
     char *outbuf = buffer;
-    char *inbuf = const_cast<char*>(val.data())+in_offset;
+    const char *inbuf = const_cast<char*>(val.data())+in_offset;
     size_t inbytes = val.length()-in_offset;
 #if defined(__SUN__) || defined(__CYGWIN__)
     if ((int)iconv(con, &(const char*)inbuf, &inbytes, &outbuf, &outbytes) <  0)
