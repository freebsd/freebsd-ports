--- tools/xml-rpc-api2cpp/XmlRpcFunction.h.orig	Mon Mar 26 05:17:50 2001
+++ tools/xml-rpc-api2cpp/XmlRpcFunction.h	Tue Mar  2 23:39:39 2004
@@ -1,27 +1,27 @@
 
 class XmlRpcFunction {
-    string mFunctionName;
-    string mMethodName;
-    string mHelp;
+    std::string mFunctionName;
+    std::string mMethodName;
+    std::string mHelp;
     XmlRpcValue mSynopsis;
 
 public: 
-    XmlRpcFunction(const string& function_name,
-		   const string& method_name,
-		   const string& help,
+    XmlRpcFunction(const std::string& function_name,
+		   const std::string& method_name,
+		   const std::string& help,
 		   XmlRpcValue synopsis);
 
     XmlRpcFunction (const XmlRpcFunction&);
     XmlRpcFunction& operator= (const XmlRpcFunction&);
     
-    void printDeclarations (ostream& out);
-    void printDefinitions  (ostream& out, const string& className);
+    void printDeclarations (std::ostream& out);
+    void printDefinitions  (std::ostream& out, const std::string& className);
 
 private:
-    void printParameters  (ostream& out, size_t synopsis_index);
-    void printDeclaration (ostream& out, size_t synopsis_index);
-    void printDefinition  (ostream& out,
-			   const string& className,
+    void printParameters  (std::ostream& out, size_t synopsis_index);
+    void printDeclaration (std::ostream& out, size_t synopsis_index);
+    void printDefinition  (std::ostream& out,
+			   const std::string& className,
 			   size_t synopsis_index);
 
     const DataType& returnType (size_t synopsis_index);
