--- varref.cxx.orig	Fri Oct 22 13:00:42 1999
+++ varref.cxx	Fri Mar 19 01:17:52 2004
@@ -19,6 +19,8 @@
 #include <latte-log.h>
 #include <mutable.h>
 
+using namespace std;
+
 Latte_VarRef::Latte_VarRef(const Latte_Wstate &ws,
 			   const Latte_FileLoc &loc,
 			   const shstring &name) :
