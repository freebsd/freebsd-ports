--- tools/xml-rpc-api2cpp/XmlRpcClass.h.orig	Mon Mar 26 08:43:07 2001
+++ tools/xml-rpc-api2cpp/XmlRpcClass.h	Tue Mar  2 23:39:39 2004
@@ -1,19 +1,19 @@
-#include <vector.h>
+#include <vector>
 
 class XmlRpcClass {
-    string mClassName;
-    vector<XmlRpcFunction> mFunctions;
+    std::string mClassName;
+    std::vector<XmlRpcFunction> mFunctions;
 
 
 public:
-    XmlRpcClass (string class_name);
+    XmlRpcClass (std::string class_name);
     XmlRpcClass (const XmlRpcClass&);
     XmlRpcClass& operator= (const XmlRpcClass&);
 
-    string className () const { return mClassName; }
+    std::string className () const { return mClassName; }
 
     void addFunction (const XmlRpcFunction& function);
 
-    void printDeclaration (ostream& out);
-    void printDefinition (ostream& out);
+    void printDeclaration (std::ostream& out);
+    void printDefinition (std::ostream& out);
 };
