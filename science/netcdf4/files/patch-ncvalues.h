--- cxx/ncvalues.h.orig	Thu Oct 29 02:10:16 1998
+++ cxx/ncvalues.h	Thu Feb  5 20:51:02 2004
@@ -14,7 +14,7 @@
 #ifdef STRSTREAM_H_SPEC
 #   include STRSTREAM_H_SPEC
 #else
-#   include <strstream.h>
+#   include <strstream>
 #endif
 #include <limits.h>
 #include <string.h>
@@ -220,7 +220,7 @@
 char* NcVal(TYPE)::as_string( long n ) const				      \
 {									      \
     char* s = new char[32];						      \
-    ostrstream ostr(s, sizeof(s));                                            \
+    std::ostrstream ostr(s, sizeof(s));                                      \
     ostr << the_values[n] << ends;              			      \
     return s;								      \
 }
