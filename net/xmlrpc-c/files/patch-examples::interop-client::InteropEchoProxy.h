--- examples/interop-client/InteropEchoProxy.h.orig	Wed Apr 25 00:17:42 2001
+++ examples/interop-client/InteropEchoProxy.h	Tue Mar  2 23:39:39 2004
@@ -12,7 +12,7 @@
 public:
     InteropEchoProxy (const XmlRpcClient& client)
         : mClient(client) {}
-    InteropEchoProxy (const string& server_url)
+    InteropEchoProxy (const std::string& server_url)
         : mClient(XmlRpcClient(server_url)) {}
     InteropEchoProxy (const InteropEchoProxy& o)
         : mClient(o.mClient) {}
@@ -23,7 +23,7 @@
     }
 
     /* Echo an arbitrary XML-RPC string. */
-    string echoString (string string1);
+    std::string echoString (std::string string1);
 
     /* Echo an arbitrary XML-RPC integer. */
     XmlRpcValue::int32 echoInteger (XmlRpcValue::int32 int1);
