--- src/XmlRpcCpp.h.orig	Thu Nov 14 09:17:52 2002
+++ src/XmlRpcCpp.h	Thu Nov 14 09:18:17 2002
@@ -45,8 +45,8 @@
 // work with our version of g++). So this header name is technically wrong.
 // Tell me what your compiler does; I can provide some autoconf magic to the
 // Right Thing on most platforms.
+using namespace std;
 #include <string>
-// using namespace std;
 
 #include <xmlrpc.h>
 #include <xmlrpc_client.h>
