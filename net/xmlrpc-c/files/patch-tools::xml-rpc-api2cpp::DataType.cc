--- tools/xml-rpc-api2cpp/DataType.cc.orig	Fri Mar 30 05:39:06 2001
+++ tools/xml-rpc-api2cpp/DataType.cc	Tue Mar  2 23:39:39 2004
@@ -1,5 +1,5 @@
-#include <iostream.h>
-#include <strstream.h>
+#include <iostream>
+#include <sstream>
 #include <stdexcept>
 
 #include <XmlRpcCpp.h>
@@ -12,12 +12,10 @@
 //  Instances of DataType know how generate code fragments for manipulating
 //  a specific XML-RPC data type.
 
-string DataType::defaultParameterBaseName (int position) const {
-    ostrstream name_stream;
-    name_stream << typeName() << position << ends;
-    string name(name_stream.str());
-    // (Ask the ostrstream to reclaim ownership of its buffer.)
-    name_stream.freeze(false);
+std::string DataType::defaultParameterBaseName (int position) const {
+    std::ostringstream name_stream;
+    name_stream << typeName() << position << std::ends;
+    std::string name(name_stream.str());
     return name;
 }
 
@@ -29,27 +27,27 @@
 
 class RawDataType : public DataType {
 public:
-    RawDataType (const string& type_name) : DataType(type_name) {}
+    RawDataType (const std::string& type_name) : DataType(type_name) {}
     
-    virtual string parameterFragment (const string& base_name) const;
-    virtual string inputConversionFragment (const string& base_name) const;
-    virtual string returnTypeFragment () const;
-    virtual string outputConversionFragment (const string& var_name) const;
+    virtual std::string parameterFragment (const std::string& base_name) const;
+    virtual std::string inputConversionFragment (const std::string& base_name) const;
+    virtual std::string returnTypeFragment () const;
+    virtual std::string outputConversionFragment (const std::string& var_name) const;
 };
 
-string RawDataType::parameterFragment (const string& base_name) const {
+std::string RawDataType::parameterFragment (const std::string& base_name) const {
     return "XmlRpcValue /*" + typeName() + "*/ " + base_name;
 }
 
-string RawDataType::inputConversionFragment (const string& base_name) const {
+std::string RawDataType::inputConversionFragment (const std::string& base_name) const {
     return base_name;
 }
 
-string RawDataType::returnTypeFragment () const {
+std::string RawDataType::returnTypeFragment () const {
     return "XmlRpcValue /*" + typeName() + "*/";
 }
 
-string RawDataType::outputConversionFragment (const string& var_name) const {
+std::string RawDataType::outputConversionFragment (const std::string& var_name) const {
     return var_name;
 }
 
@@ -60,26 +58,26 @@
 //  Other types can be easily converted to and from a single native type.
 
 class SimpleDataType : public DataType {
-    string mNativeType;
-    string mMakerFunc;
-    string mGetterFunc;
+    std::string mNativeType;
+    std::string mMakerFunc;
+    std::string mGetterFunc;
 
 public:
-    SimpleDataType (const string& type_name,
-		    const string& native_type,
-		    const string& maker_func,
-		    const string& getter_func);
-
-    virtual string parameterFragment (const string& base_name) const;
-    virtual string inputConversionFragment (const string& base_name) const;
-    virtual string returnTypeFragment () const;
-    virtual string outputConversionFragment (const string& var_name) const;
+    SimpleDataType (const std::string& type_name,
+		    const std::string& native_type,
+		    const std::string& maker_func,
+		    const std::string& getter_func);
+
+    virtual std::string parameterFragment (const std::string& base_name) const;
+    virtual std::string inputConversionFragment (const std::string& base_name) const;
+    virtual std::string returnTypeFragment () const;
+    virtual std::string outputConversionFragment (const std::string& var_name) const;
 };
 
-SimpleDataType::SimpleDataType (const string& type_name,
-				const string& native_type,
-				const string& maker_func,
-				const string& getter_func)
+SimpleDataType::SimpleDataType (const std::string& type_name,
+				const std::string& native_type,
+				const std::string& maker_func,
+				const std::string& getter_func)
     : DataType(type_name),
       mNativeType(native_type),
       mMakerFunc(maker_func),
@@ -87,20 +85,20 @@
 {
 }
 
-string SimpleDataType::parameterFragment (const string& base_name) const {
+std::string SimpleDataType::parameterFragment (const std::string& base_name) const {
     return mNativeType + " " + base_name;
 }
 
-string SimpleDataType::inputConversionFragment (const string& base_name) const
+std::string SimpleDataType::inputConversionFragment (const std::string& base_name) const
 {
     return mMakerFunc + "(" + base_name + ")";
 }
 
-string SimpleDataType::returnTypeFragment () const {
+std::string SimpleDataType::returnTypeFragment () const {
     return mNativeType; 
 }
 
-string SimpleDataType::outputConversionFragment (const string& var_name) const
+std::string SimpleDataType::outputConversionFragment (const std::string& var_name) const
 {
     return var_name + "." + mGetterFunc + "()";
 }
@@ -116,26 +114,26 @@
 public:
     VoidDataType () : DataType("void") {}
     
-    virtual string parameterFragment (const string& base_name) const;
-    virtual string inputConversionFragment (const string& base_name) const;
-    virtual string returnTypeFragment () const;
-    virtual string outputConversionFragment (const string& var_name) const;
+    virtual std::string parameterFragment (const std::string& base_name) const;
+    virtual std::string inputConversionFragment (const std::string& base_name) const;
+    virtual std::string returnTypeFragment () const;
+    virtual std::string outputConversionFragment (const std::string& var_name) const;
 };
 
-string VoidDataType::parameterFragment (const string& base_name) const {
-    throw domain_error("Can't handle functions with 'void' arguments'");
+std::string VoidDataType::parameterFragment (const std::string& base_name) const {
+    throw std::domain_error("Can't handle functions with 'void' arguments'");
     
 }
 
-string VoidDataType::inputConversionFragment (const string& base_name) const {
-    throw domain_error("Can't handle functions with 'void' arguments'");
+std::string VoidDataType::inputConversionFragment (const std::string& base_name) const {
+    throw std::domain_error("Can't handle functions with 'void' arguments'");
 }
 
-string VoidDataType::returnTypeFragment () const {
+std::string VoidDataType::returnTypeFragment () const {
     return "void";
 }
 
-string VoidDataType::outputConversionFragment (const string& var_name) const {
+std::string VoidDataType::outputConversionFragment (const std::string& var_name) const {
     return "/* Return value ignored. */";
 }
 
@@ -166,7 +164,7 @@
 
 VoidDataType voidType;
 
-const DataType& findDataType (const string& name) {
+const DataType& findDataType (const std::string& name) {
     if (name == "int" || name == "i4")
 	return intType;
     else if (name == "boolean")
@@ -186,7 +184,7 @@
     else if (name == "void")
 	return voidType;
     else
-	throw domain_error("Unknown XML-RPC type " + name);
+	throw std::domain_error("Unknown XML-RPC type " + name);
     
     // This code should never be executed.
     XMLRPC_ASSERT(0);
