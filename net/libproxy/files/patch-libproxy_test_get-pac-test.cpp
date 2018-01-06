libc++ doesn't like "using namespace std" in C++11

libproxy/test/get-pac-test.cpp:48:10: error: assigning to 'int' from incompatible type '__bind<int &, sockaddr *, unsigned long>'
                        ret = bind(m_sock, (sockaddr*)&addr, sizeof (struct sockaddr_in));
                              ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--- libproxy/test/get-pac-test.cpp.orig	2016-01-12 16:41:07 UTC
+++ libproxy/test/get-pac-test.cpp
@@ -45,7 +45,7 @@ class TestServer {
 
 			setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(i));
 
-			ret = bind(m_sock, (sockaddr*)&addr, sizeof (struct sockaddr_in));
+			ret = ::bind(m_sock, (sockaddr*)&addr, sizeof (struct sockaddr_in));
 			assert(!ret);
 
 			ret = listen(m_sock, 1);
