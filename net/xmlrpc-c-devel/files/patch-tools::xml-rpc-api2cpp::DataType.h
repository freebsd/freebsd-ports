--- tools/xml-rpc-api2cpp/DataType.h.orig	Mon Mar 26 03:34:53 2001
+++ tools/xml-rpc-api2cpp/DataType.h	Tue Mar  2 23:39:39 2004
@@ -1,28 +1,28 @@
 
 class DataType {
-    string mTypeName;
+    std::string mTypeName;
 
     DataType (const DataType&) { XMLRPC_ASSERT(0); }
     DataType& operator= (const DataType&) { XMLRPC_ASSERT(0); return *this; }
 
 public:
-    DataType (const string& type_name) : mTypeName(type_name) {}
+    DataType (const std::string& type_name) : mTypeName(type_name) {}
     virtual ~DataType () {}
 
     // Return the name for this XML-RPC type.
-    virtual string typeName () const { return mTypeName; }
+    virtual std::string typeName () const { return mTypeName; }
 
     // Given a parameter position, calculate a unique base name for all
     // parameter-related variables.
-    virtual string defaultParameterBaseName (int position) const;
+    virtual std::string defaultParameterBaseName (int position) const;
 
     // Virtual functions for processing parameters.
-    virtual string parameterFragment (const string& base_name) const = 0;
-    virtual string inputConversionFragment (const string& base_name) const = 0;
+    virtual std::string parameterFragment (const std::string& base_name) const = 0;
+    virtual std::string inputConversionFragment (const std::string& base_name) const = 0;
 
     // Virtual functions for processing return values.
-    virtual string returnTypeFragment () const = 0;
-    virtual string outputConversionFragment (const string& var_name) const = 0;
+    virtual std::string returnTypeFragment () const = 0;
+    virtual std::string outputConversionFragment (const std::string& var_name) const = 0;
 };
 
-const DataType& findDataType (const string& name);
+const DataType& findDataType (const std::string& name);
