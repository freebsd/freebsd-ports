--- tools/xml-rpc-api2cpp/XmlRpcClass.cc.orig	Mon Mar 26 08:49:19 2001
+++ tools/xml-rpc-api2cpp/XmlRpcClass.cc	Tue Mar  2 23:39:39 2004
@@ -1,6 +1,6 @@
-#include <iostream.h>
+#include <iostream>
 #include <stdexcept>
-#include <vector.h>
+#include <vector>
 
 #include <XmlRpcCpp.h>
 #include "DataType.h"
@@ -14,7 +14,7 @@
 //  This class stores information about a proxy class, and knows how to
 //  generate code.
 
-XmlRpcClass::XmlRpcClass (string class_name)
+XmlRpcClass::XmlRpcClass (std::string class_name)
     : mClassName(class_name)
 {
 }
@@ -39,37 +39,37 @@
     mFunctions.push_back(function);
 }
 
-void XmlRpcClass::printDeclaration (ostream& out)
+void XmlRpcClass::printDeclaration (std::ostream& out)
 {
-    cout << "class " << mClassName << " {" << endl;
-    cout << "    XmlRpcClient mClient;" << endl;
-    cout << endl;
-    cout << "public:" << endl;
-    cout << "    " << mClassName << " (const XmlRpcClient& client)" << endl;
-    cout << "        : mClient(client) {}" << endl;
-    cout << "    " << mClassName << " (const string& server_url)" << endl;
-    cout << "        : mClient(XmlRpcClient(server_url)) {}" << endl;
-    cout << "    " << mClassName << " (const " << mClassName << "& o)" << endl;
-    cout << "        : mClient(o.mClient) {}" << endl;
-    cout << endl;
-    cout << "    " << mClassName << "& operator= (const "
-	 << mClassName << "& o) {" << endl;
-    cout << "        if (this != &o) mClient = o.mClient;" << endl;
-    cout << "        return *this;" << endl;
-    cout << "    }" << endl;
+    std::cout << "class " << mClassName << " {" << std::endl;
+    std::cout << "    XmlRpcClient mClient;" << std::endl;
+    std::cout << std::endl;
+    std::cout << "public:" << std::endl;
+    std::cout << "    " << mClassName << " (const XmlRpcClient& client)" << std::endl;
+    std::cout << "        : mClient(client) {}" << std::endl;
+    std::cout << "    " << mClassName << " (const std::string& server_url)" << std::endl;
+    std::cout << "        : mClient(XmlRpcClient(server_url)) {}" << std::endl;
+    std::cout << "    " << mClassName << " (const " << mClassName << "& o)" << std::endl;
+    std::cout << "        : mClient(o.mClient) {}" << std::endl;
+    std::cout << std::endl;
+    std::cout << "    " << mClassName << "& operator= (const "
+	 << mClassName << "& o) {" << std::endl;
+    std::cout << "        if (this != &o) mClient = o.mClient;" << std::endl;
+    std::cout << "        return *this;" << std::endl;
+    std::cout << "    }" << std::endl;
 
-    vector<XmlRpcFunction>::iterator f;
+    std::vector<XmlRpcFunction>::iterator f;
     for (f = mFunctions.begin(); f < mFunctions.end(); ++f) {
-	f->printDeclarations(cout);
+	f->printDeclarations(std::cout);
     }
 
-    cout << "};" << endl;    
+    std::cout << "};" << std::endl;    
 }
 
-void XmlRpcClass::printDefinition (ostream& out)
+void XmlRpcClass::printDefinition (std::ostream& out)
 {
-    vector<XmlRpcFunction>::iterator f;
+    std::vector<XmlRpcFunction>::iterator f;
     for (f = mFunctions.begin(); f < mFunctions.end(); ++f) {
-	f->printDefinitions(cout, mClassName);
+	f->printDefinitions(std::cout, mClassName);
     }
 }
