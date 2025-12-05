--- app/rec/rec_client_core/src/job/ftp_upload_thread.cpp.orig	2024-09-08 02:28:28 UTC
+++ app/rec/rec_client_core/src/job/ftp_upload_thread.cpp
@@ -44,6 +44,7 @@
   #include <unistd.h>
 
   #include <sys/types.h>   // getaddrinfo
+  #include <netinet/in.h>  // sockaddr_in, sockaddr_in6
   #include <sys/socket.h>  // getaddrinfo
   #include <netdb.h>       // getaddrinfo
 
