--- tools/xml-rpc-api2cpp/XmlRpcFunction.cc.orig	Mon Mar 26 08:21:07 2001
+++ tools/xml-rpc-api2cpp/XmlRpcFunction.cc	Tue Mar  2 23:39:39 2004
@@ -1,4 +1,4 @@
-#include <iostream.h>
+#include <iostream>
 #include <stdexcept>
 
 #include <XmlRpcCpp.h>
@@ -12,9 +12,9 @@
 //  Contains everything we know about a given server function, and knows
 //  how to print local bindings.
 
-XmlRpcFunction::XmlRpcFunction(const string& function_name,
-			       const string& method_name,
-			       const string& help,
+XmlRpcFunction::XmlRpcFunction(const std::string& function_name,
+			       const std::string& method_name,
+			       const std::string& help,
 			       XmlRpcValue synopsis)
     : mFunctionName(function_name), mMethodName(method_name),
       mHelp(help), mSynopsis(synopsis)
@@ -37,10 +37,10 @@
     return *this;
 }
 
-void XmlRpcFunction::printDeclarations (ostream& out) {
+void XmlRpcFunction::printDeclarations (std::ostream& out) {
 
     // XXX - Do a sloppy job of printing documentation.
-    out << endl << "    /* " << mHelp << " */" << endl;
+    out << std::endl << "    /* " << mHelp << " */" << std::endl;
 
     // Print each declaration.
     size_t end = mSynopsis.arraySize();
@@ -48,16 +48,16 @@
 	printDeclaration(out, i);
 }
 
-void XmlRpcFunction::printDefinitions (ostream& out, const string& className) {
+void XmlRpcFunction::printDefinitions (std::ostream& out, const std::string& className) {
     size_t end = mSynopsis.arraySize();
     for (size_t i = 0; i < end; i++) {
-	out << endl;
+	out << std::endl;
 	printDefinition(out, className, i);
     }
 }
 
 // Print the parameter declarations.
-void XmlRpcFunction::printParameters (ostream& out, size_t synopsis_index) {
+void XmlRpcFunction::printParameters (std::ostream& out, size_t synopsis_index) {
     size_t end = parameterCount(synopsis_index);
     bool first = true;
     for (size_t i = 0; i < end; i++) {
@@ -67,47 +67,47 @@
 	    out << ", ";
 
 	const DataType& ptype (parameterType(synopsis_index, i));
-	string basename = ptype.defaultParameterBaseName(i + 1);
+	std::string basename = ptype.defaultParameterBaseName(i + 1);
 	out << ptype.parameterFragment(basename);
     }
 }
 
-void XmlRpcFunction::printDeclaration (ostream& out, size_t synopsis_index) {
+void XmlRpcFunction::printDeclaration (std::ostream& out, size_t synopsis_index) {
     const DataType& rtype (returnType(synopsis_index));
     out << "    " << rtype.returnTypeFragment() << " "
 	<< mFunctionName << " (";
     printParameters(out, synopsis_index);
-    out << ");" << endl;
+    out << ");" << std::endl;
 }
 
-void XmlRpcFunction::printDefinition (ostream& out,
-				      const string& className,
+void XmlRpcFunction::printDefinition (std::ostream& out,
+				      const std::string& className,
 				      size_t synopsis_index)
 {
     const DataType& rtype (returnType(synopsis_index));
     out << rtype.returnTypeFragment() << " "
 	<< className << "::" << mFunctionName << " (";
     printParameters(out, synopsis_index);
-    out << ") {" << endl;    
-    out << "    XmlRpcValue params = XmlRpcValue::makeArray();" << endl;
+    out << ") {" << std::endl;    
+    out << "    XmlRpcValue params = XmlRpcValue::makeArray();" << std::endl;
 
     /* Emit code to convert the parameters into an array of XML-RPC objects. */
     size_t end = parameterCount(synopsis_index);
     for (size_t i = 0; i < end; i++) {
 	const DataType& ptype (parameterType(synopsis_index, i));
-	string basename = ptype.defaultParameterBaseName(i + 1);
+	std::string basename = ptype.defaultParameterBaseName(i + 1);
 	out << "    params.arrayAppendItem("
-	    << ptype.inputConversionFragment(basename) << ");" << endl;
+	    << ptype.inputConversionFragment(basename) << ");" << std::endl;
     }
 
     /* Emit the function call.*/
     out << "    XmlRpcValue result = this->mClient.call(\""
-	<< mMethodName << "\", params);" << endl;    
+	<< mMethodName << "\", params);" << std::endl;    
 
     /* Emit the return statement. */
     out << "    return " << rtype.outputConversionFragment("result")
-	<< ";" << endl;
-    out << "}" << endl;
+	<< ";" << std::endl;
+    out << "}" << std::endl;
 }
 
 const DataType& XmlRpcFunction::returnType (size_t synopsis_index) {
@@ -119,7 +119,7 @@
     XmlRpcValue func_synop = mSynopsis.arrayGetItem(synopsis_index);
     size_t size = func_synop.arraySize();
     if (size < 1)
-	throw domain_error("Synopsis contained no items");
+	throw std::domain_error("Synopsis contained no items");
     return size - 1;
 }
 
