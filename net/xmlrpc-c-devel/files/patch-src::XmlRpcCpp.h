--- src/XmlRpcCpp.h.orig	Sat Apr 14 03:46:16 2001
+++ src/XmlRpcCpp.h	Tue Mar  2 23:39:39 2004
@@ -71,12 +71,12 @@
 
 public:
                  XmlRpcFault (const XmlRpcFault &fault);
-                 XmlRpcFault (const int faultCode, const string faultString);
+                 XmlRpcFault (const int faultCode, const std::string faultString);
                  XmlRpcFault (const xmlrpc_env *env);
                 ~XmlRpcFault (void);
 
     int          getFaultCode (void) const;
-    string       getFaultString (void) const;
+    std::string  getFaultString (void) const;
     xmlrpc_env  *getFaultEnv (void);
 };
 
@@ -167,8 +167,8 @@
     static XmlRpcValue makeInt      (const XmlRpcValue::int32 i);
     static XmlRpcValue makeBool     (const bool b);
     static XmlRpcValue makeDouble   (const double d);
-    static XmlRpcValue makeDateTime (const string& dateTime);
-    static XmlRpcValue makeString   (const string& str);
+    static XmlRpcValue makeDateTime (const std::string& dateTime);
+    static XmlRpcValue makeString   (const std::string& str);
     static XmlRpcValue makeString   (const char *const str);
     static XmlRpcValue makeString   (const char *const str, size_t len);
     static XmlRpcValue makeArray    (void);
@@ -185,8 +185,8 @@
     XmlRpcValue::int32 getInt   (void) const;
     bool         getBool        (void) const;
     double       getDouble      (void) const;
-    string       getRawDateTime (void) const;
-    string       getString      (void) const;
+    std::string  getRawDateTime (void) const;
+    std::string  getString      (void) const;
     XmlRpcValue  getArray       (void) const;
     XmlRpcValue  getStruct      (void) const;
 
@@ -209,11 +209,11 @@
     // Struct functions. These will throw an XmlRpcFault if the value
     // isn't a struct.
     size_t       structSize (void);
-    bool         structHasKey (const string& key);
-    XmlRpcValue  structGetValue (const string& key);
-    void         structSetValue (const string& key, const XmlRpcValue& value);
+    bool         structHasKey (const std::string& key);
+    XmlRpcValue  structGetValue (const std::string& key);
+    void         structSetValue (const std::string& key, const XmlRpcValue& value);
     void         structGetKeyAndValue (const int index,
-				       string& out_key,
+				       std::string& out_key,
 				       XmlRpcValue& out_value);
 };
 
@@ -265,19 +265,19 @@
 class XmlRpcClient {
 
 private:
-    string mServerUrl;
+    std::string mServerUrl;
 
 public:
-    static void Initialize (string appname, string appversion);
+    static void Initialize (std::string appname, std::string appversion);
     static void Terminate (void);
 
-    XmlRpcClient (const string& server_url) : mServerUrl(server_url) {}
+    XmlRpcClient (const std::string& server_url) : mServerUrl(server_url) {}
     ~XmlRpcClient (void) {}
 
     XmlRpcClient (const XmlRpcClient& client);
     XmlRpcClient& operator= (const XmlRpcClient& client);
 
-    XmlRpcValue call (string method_name, XmlRpcValue param_array);
+    XmlRpcValue call (std::string method_name, XmlRpcValue param_array);
 };
 
 
@@ -299,7 +299,7 @@
     return *this;
 }
 
-inline void XmlRpcClient::Initialize (string appname, string appversion) {
+inline void XmlRpcClient::Initialize (std::string appname, std::string appversion) {
     xmlrpc_client_init(XMLRPC_CLIENT_NO_FLAGS,
 		       const_cast<char*>(appname.c_str()),
 		       const_cast<char*>(appversion.c_str()));
@@ -309,7 +309,7 @@
     xmlrpc_client_cleanup();
 }
 
-inline XmlRpcValue XmlRpcClient::call (string method_name,
+inline XmlRpcValue XmlRpcClient::call (std::string method_name,
 				       XmlRpcValue param_array)
 {
     XmlRpcEnv env;
