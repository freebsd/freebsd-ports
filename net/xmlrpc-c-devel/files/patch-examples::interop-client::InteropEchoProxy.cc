--- examples/interop-client/InteropEchoProxy.cc.orig	Wed Apr 25 00:17:25 2001
+++ examples/interop-client/InteropEchoProxy.cc	Tue Mar  2 23:39:39 2004
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
@@ -55,7 +55,7 @@
 #include <XmlRpcCpp.h>
 #include "InteropEchoProxy.h"
 
-string InteropEchoProxy::echoString (string string1) {
+std::string InteropEchoProxy::echoString (std::string string1) {
     XmlRpcValue params = XmlRpcValue::makeArray();
     params.arrayAppendItem(XmlRpcValue::makeString(string1));
     XmlRpcValue result = this->mClient.call("interopEchoTests.echoString", params);
