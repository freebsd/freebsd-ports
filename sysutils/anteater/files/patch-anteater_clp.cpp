
$FreeBSD$

--- anteater/clp.cpp.orig	Thu May 24 19:28:50 2001
+++ anteater/clp.cpp	Tue Nov  5 13:20:12 2002
@@ -502,7 +502,7 @@
   return true;
 };
 
-bool clp::parseError( const std::string &wrong, const long line = 0 )
+bool clp::parseError( const std::string &wrong, const long line)
 {
   std::cerr << "Ooops! I don't understand your parameter \"" << wrong << "\"..." << std::endl;
   std::cerr << "Please check the syntax or read the manual." << std::endl << std::endl;
