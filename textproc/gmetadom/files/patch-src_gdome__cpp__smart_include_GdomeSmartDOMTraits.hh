./../include/GdomeSmartDOMTraits.hh:101:25: error: non-constant-expression cannot be narrowed from type 'std::__1::char_traits<unsigned short>::int_type' (aka 'unsigned long') to 'std::__1::char_traits<unsigned short>::char_type' (aka 'unsigned short') in initializer list [-Wc++11-narrowing]
      char_type __r = { __c };
                        ^~~

--- src/gdome_cpp_smart/include/GdomeSmartDOMTraits.hh.orig	2018-07-29 11:48:09 UTC
+++ src/gdome_cpp_smart/include/GdomeSmartDOMTraits.hh
@@ -98,7 +98,7 @@ namespace std {
     static char_type 
     to_char_type(const int_type& __c)
     {
-      char_type __r = { __c };
+      char_type __r = { static_cast<char_type>(__c) };
       return __r;
     }
 
