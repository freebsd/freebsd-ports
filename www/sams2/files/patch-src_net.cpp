Fix build with Clang6: stringstream doesn't have a viable overload
for ostream::operator<< . It does with Clang5. Use str() explicitly.

--- src/net.cpp.orig	2018-07-04 11:24:43 UTC
+++ src/net.cpp
@@ -156,9 +156,10 @@ string Net::asString ()
 
   s << _net.c_str ();
 
-  DEBUG (DEBUG8, "[" << this << "->" << __FUNCTION__ << "] = " << s);
+  string r = s.str ();
+  DEBUG (DEBUG8, "[" << this << "->" << __FUNCTION__ << "] = " << r);
 
-  return s.str ();
+  return r;
 }
 
 
