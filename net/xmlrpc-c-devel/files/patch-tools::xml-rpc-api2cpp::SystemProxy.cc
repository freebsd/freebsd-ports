--- tools/xml-rpc-api2cpp/SystemProxy.cc.orig	Mon Mar 26 08:46:28 2001
+++ tools/xml-rpc-api2cpp/SystemProxy.cc	Tue Mar  2 23:39:39 2004
@@ -10,14 +10,14 @@
     return result;
 }
 
-XmlRpcValue /*array*/ SystemProxy::methodSignature (string string1) {
+XmlRpcValue /*array*/ SystemProxy::methodSignature (std::string string1) {
     XmlRpcValue params = XmlRpcValue::makeArray();
     params.arrayAppendItem(XmlRpcValue::makeString(string1));
     XmlRpcValue result = this->mClient.call("system.methodSignature", params);
     return result;
 }
 
-string SystemProxy::methodHelp (string string1) {
+std::string SystemProxy::methodHelp (std::string string1) {
     XmlRpcValue params = XmlRpcValue::makeArray();
     params.arrayAppendItem(XmlRpcValue::makeString(string1));
     XmlRpcValue result = this->mClient.call("system.methodHelp", params);
