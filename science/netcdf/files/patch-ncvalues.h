--- cxx/ncvalues.h.orig	Wed Oct 28 18:10:16 1998
+++ cxx/ncvalues.h	Sat Feb  7 14:03:13 2004
@@ -10,12 +10,9 @@
 #ifndef Ncvalues_def
 #define Ncvalues_def
 
-#include <iostream.h>
-#ifdef STRSTREAM_H_SPEC
-#   include STRSTREAM_H_SPEC
-#else
-#   include <strstream.h>
-#endif
+#include <bitset>
+#include <iostream>
+#include <sstream>
 #include <limits.h>
 #include <string.h>
 #include "netcdf.h"
@@ -24,6 +21,8 @@
 
 #define NC_UNSPECIFIED ((nc_type)0)
 
+using namespace std;
+
 enum NcType 
 {
   ncNoType = NC_UNSPECIFIED, 
@@ -219,9 +218,12 @@
 #define as_string_implement(TYPE)					      \
 char* NcVal(TYPE)::as_string( long n ) const				      \
 {									      \
-    char* s = new char[32];						      \
-    ostrstream ostr(s, sizeof(s));                                            \
+    static char s[32];							      \
+    ostringstream ostr;                                                       \
     ostr << the_values[n] << ends;              			      \
+    std::string data( ostr.str() );					      \
+    strncpy( s, data.data(), sizeof(s)-1);				      \
+    s[ sizeof(s)-1 ] = 0;						      \
     return s;								      \
 }
 
