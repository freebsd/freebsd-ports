libc++ doesn't like "using namespace std" in C++11

server_abyss.cpp:88:14: error: assigning to 'int' from incompatible type '__bind<int &, sockaddr *,
      unsigned long>'
        rc = bind(this->fd, (struct sockaddr *)&sockAddr, sizeof(sockAddr));
             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--- test/cpp/server_abyss.cpp.orig	2014-08-29 18:59:00 UTC
+++ test/cpp/server_abyss.cpp
@@ -85,7 +85,7 @@ class boundSocket { (public)
         sockAddr.sin_port   = htons(portNumber);
         sockAddr.sin_addr.s_addr = 0;
 
-        rc = bind(this->fd, (struct sockaddr *)&sockAddr, sizeof(sockAddr));
+        rc = ::bind(this->fd, (struct sockaddr *)&sockAddr, sizeof(sockAddr));
         
         if (rc != 0) {
             closesock(this->fd);
