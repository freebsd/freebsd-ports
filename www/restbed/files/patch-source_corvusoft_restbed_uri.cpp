--- source/corvusoft/restbed/uri.cpp.orig	2021-09-11 00:09:45 UTC
+++ source/corvusoft/restbed/uri.cpp
@@ -100,7 +100,7 @@ namespace restbed
     
     string Uri::decode( const string& value )
     {
-        static const char hex_to_dec[256] = 
+        static const signed char hex_to_dec[256] = 
         {
             /*       0  1  2  3   4  5  6  7   8  9  A  B   C  D  E  F */
             /* 0 */ -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
