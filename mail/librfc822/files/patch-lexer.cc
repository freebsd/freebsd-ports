--- lexer.cpp.orig	2008-03-03 23:44:57.000000000 +0200
+++ lexer.cpp	2008-03-03 23:44:35.000000000 +0200
@@ -13,7 +13,7 @@
 #include "rfc822.hpp"
 using namespace std;
 
-ostream & operator<< (ostream & os, const token & t)
+std::ostream & operator<< (std::ostream& os, const token & t)
 {
   switch(t.type)
   {
