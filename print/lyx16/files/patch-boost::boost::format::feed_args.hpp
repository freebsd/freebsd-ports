$NetBSD$

--- ./boost/boost/format/feed_args.hpp.orig	2002-11-20 10:20:54.000000000 -0700
+++ ./boost/boost/format/feed_args.hpp
@@ -34,7 +34,7 @@ namespace  {
 
   template<class Tr, class Ch> inline
   void empty_buf(BOOST_IO_STD basic_ostringstream<Ch,Tr> & os) {
-    static const std::basic_string<Ch, Tr> emptyStr; // avoids 2 cases ( "" and  L"" )
+    const std::basic_string<Ch, Tr> emptyStr; // avoids 2 cases ( "" and  L"" )
     os.str(emptyStr);
   }
 
