--- reader.cxx.orig	Sun Oct 17 22:40:42 1999
+++ reader.cxx	Fri Mar 19 01:17:52 2004
@@ -17,6 +17,8 @@
 
 #include <latte.h>
 
+using namespace std;
+
 Latte_Reader::Latte_Reader(istream &i, const shstring &f) :
   yyFlexLexer(&i),
   m_column(0), m_filename(f),
