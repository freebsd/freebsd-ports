--- fileloc.cxx.orig	Thu Dec  3 07:54:01 1998
+++ fileloc.cxx	Fri Mar 19 01:17:52 2004
@@ -17,6 +17,8 @@
 
 #include <latte.h>
 
+using namespace std;
+
 Latte_FileLoc::Latte_FileLoc(const shstring &filename,
 			     unsigned int lineno) :
   m_filename(filename), m_lineno(lineno)
