--- iputils.hh.orig	2023-07-20 17:03:02 UTC
+++ iputils.hh
@@ -89,7 +89,7 @@ union ComboAddress {
       return memcmp(&sin6.sin6_addr.s6_addr, &rhs.sin6.sin6_addr.s6_addr, 16) > 0;
   }
 
-  struct addressOnlyLessThan: public std::binary_function<string, string, bool>
+  struct addressOnlyLessThan: public std::__binary_function<string, string, bool>
   {
     bool operator()(const ComboAddress& a, const ComboAddress& b) const
     {
