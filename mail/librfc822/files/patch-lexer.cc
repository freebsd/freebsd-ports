--- lexer.cc.orig	Mon Apr 14 02:34:51 2003
+++ lexer.cc	Mon Apr 14 02:34:55 2003
@@ -6,7 +6,7 @@
 #include "rfc822.hh"
 using namespace std;
 
-ostream & operator<< (ostream & os, const token & t)
+std::ostream & operator<< (std::ostream& os, const token & t)
     {
     switch(t.type)
 	{
