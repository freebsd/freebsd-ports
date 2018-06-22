First hunk:
libc++ doesn't like "using namespace std" in C++11

libproxy/test/get-pac-test.cpp:48:10: error: assigning to 'int' from incompatible type '__bind<int &, sockaddr *, unsigned long>'
                        ret = bind(m_sock, (sockaddr*)&addr, sizeof (struct sockaddr_in));
                              ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Second hunk:
Fix typo.

--- libproxy/test/get-pac-test.cpp.orig	2017-05-11 11:33:33.000000000 +0200
+++ libproxy/test/get-pac-test.cpp	2018-06-02 14:32:22.796000000 +0200
@@ -52,7 +52,7 @@
 
 			setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(i));
 
-			ret = bind(m_sock, (sockaddr*)&addr, sizeof (struct sockaddr_in));
+			ret = ::bind(m_sock, (sockaddr*)&addr, sizeof (struct sockaddr_in));
 			assert(!ret);
 
 			ret = listen(m_sock, 1);
@@ -130,7 +130,7 @@
 
 #ifdef SO_NOSIGPIPE
 			int i = 1;
-			setsockopt(c_sock, SOL_SOCKET, SO_NOSIGPIPE, &i, sizeof(i));
+			setsockopt(csock, SOL_SOCKET, SO_NOSIGPIPE, &i, sizeof(i));
 #endif
 
 			// Read request
