--- src/XmlRpcCpp.cc.orig	Sat Apr 14 03:43:55 2001
+++ src/XmlRpcCpp.cc	Tue Mar  2 23:39:39 2004
@@ -38,7 +38,7 @@
 			 fault.mFault.fault_string);
 }
 
-XmlRpcFault::XmlRpcFault (const int faultCode, const string faultString) {
+XmlRpcFault::XmlRpcFault (const int faultCode, const std::string faultString) {
     xmlrpc_env_init(&mFault);
     xmlrpc_env_set_fault(&mFault, faultCode,
 			 const_cast<char*>(faultString.c_str()));
@@ -57,9 +57,9 @@
     xmlrpc_env_clean(&mFault);
 }
 
-string XmlRpcFault::getFaultString (void) const {
+std::string XmlRpcFault::getFaultString (void) const {
     XMLRPC_ASSERT(mFault.fault_occurred);
-    return string(mFault.fault_string);
+    return std::string(mFault.fault_string);
 }
 
 
@@ -117,7 +117,7 @@
     return XmlRpcValue(value, CONSUME_REFERENCE);
 }
 
-XmlRpcValue XmlRpcValue::makeDateTime (const string& dateTime) {
+XmlRpcValue XmlRpcValue::makeDateTime (const std::string& dateTime) {
     XmlRpcEnv env;
     xmlrpc_value *value;
     const char *data = dateTime.c_str(); // Make sure we're not using wchar_t.
@@ -126,7 +126,7 @@
     return XmlRpcValue(value, CONSUME_REFERENCE);    
 }
 
-XmlRpcValue XmlRpcValue::makeString (const string& str) {
+XmlRpcValue XmlRpcValue::makeString (const std::string& str) {
     XmlRpcEnv env;
     const char *data = str.data();      // Make sure we're not using wchar_t.
     size_t size = str.size();
@@ -196,21 +196,21 @@
     return result;
 }
 
-string XmlRpcValue::getRawDateTime (void) const {
+std::string XmlRpcValue::getRawDateTime (void) const {
     XmlRpcEnv env;
     char *result;
     xmlrpc_parse_value(env, mValue, "8", &result);
     env.throwIfFaultOccurred();
-    return string(result);
+    return std::string(result);
 }
 
-string XmlRpcValue::getString (void) const {
+std::string XmlRpcValue::getString (void) const {
     XmlRpcEnv env;
     char *result;
     size_t result_len;
     xmlrpc_parse_value(env, mValue, "s#", &result, &result_len);
     env.throwIfFaultOccurred();
-    return string(result, result_len);
+    return std::string(result, result_len);
     
 }
 
@@ -265,7 +265,7 @@
     return result;
 }
 
-bool XmlRpcValue::structHasKey (const string& key) {
+bool XmlRpcValue::structHasKey (const std::string& key) {
     XmlRpcEnv env;
     const char *keystr = key.data();
     size_t keylen = key.size();
@@ -275,7 +275,7 @@
     return result;
 }
 
-XmlRpcValue XmlRpcValue::structGetValue (const string& key) {
+XmlRpcValue XmlRpcValue::structGetValue (const std::string& key) {
     XmlRpcEnv env;
     const char *keystr = key.data();
     size_t keylen = key.size();
@@ -286,7 +286,7 @@
     return XmlRpcValue(result);
 }
 
-void XmlRpcValue::structSetValue (const string& key, const XmlRpcValue& value)
+void XmlRpcValue::structSetValue (const std::string& key, const XmlRpcValue& value)
 {
     XmlRpcEnv env;
     const char *keystr = key.data();
@@ -297,7 +297,7 @@
 }
 
 void XmlRpcValue::structGetKeyAndValue (const int index,
-					string& out_key,
+					std::string& out_key,
 					XmlRpcValue& out_value)
 {
     XmlRpcEnv env;
