--- include/xmlrpc-c/base.hpp.orig	2011-07-26 14:56:50.000000000 -0300
+++ include/xmlrpc-c/base.hpp	2011-07-27 09:46:38.000000000 -0300
@@ -226,28 +226,6 @@
 
 
 
-template<class InputIterator> xmlrpc_c::value_array
-arrayValueSlice(InputIterator begin,
-                InputIterator end) {
-/*----------------------------------------------------------------------------
-  convert C++ iterator pair to XML-RPC array
------------------------------------------------------------------------------*/
-    carray ret;
-    for (InputIterator p = begin; p != end; ++p) {
-        ret.push_back(toValue(*p));
-    }
-    return xmlrpc_c::value_array(ret);
-}
-
-template<class MemberClass> inline xmlrpc_c::value_array
-arrayValueArray(const MemberClass * const in,
-                size_t              const size) {
-/*----------------------------------------------------------------------------
-  convert C++ array to XML-RPC array
------------------------------------------------------------------------------*/
-    return arrayValueSlice(in, in + size);
-}
-
 class XMLRPC_DLLEXPORT value_nil : public value {
 public:
     value_nil();
@@ -296,7 +274,7 @@
 }
 
 inline xmlrpc_c::value_bytestring
-    toValue(cbytestring const& x) {
+toValue(cbytestring const& x) {
     return xmlrpc_c::value_bytestring(x);
 }
 
@@ -324,6 +302,19 @@
     return xmlrpc_c::value_struct(ret);
 }
 
+template<class InputIterator> xmlrpc_c::value_array
+arrayValueSlice(InputIterator begin,
+                InputIterator end) {
+/*----------------------------------------------------------------------------
+  convert C++ iterator pair to XML-RPC array
+-----------------------------------------------------------------------------*/
+    carray ret;
+    for (InputIterator p = begin; p != end; ++p) {
+        ret.push_back(toValue(*p));
+    }
+    return xmlrpc_c::value_array(ret);
+}
+
 template<class T> inline xmlrpc_c::value_array
 toValue(std::vector<T> const& in) {
 /*----------------------------------------------------------------------------
@@ -398,6 +389,15 @@
     }
 }
 
+template<class MemberClass> inline xmlrpc_c::value_array
+arrayValueArray(const MemberClass * const in,
+                size_t              const size) {
+/*----------------------------------------------------------------------------
+  convert C++ array to XML-RPC array
+-----------------------------------------------------------------------------*/
+    return arrayValueSlice(in, in + size);
+}
+
 class XMLRPC_DLLEXPORT fault {
 /*----------------------------------------------------------------------------
    This is an XML-RPC fault.
