--- src/util/string_util.cpp.orig	2012-10-04 00:35:16.000000000 +0200
+++ src/util/string_util.cpp	2014-09-12 11:43:08.000000000 +0200
@@ -18,6 +18,9 @@
 #include <cerrno>
 #include <cstdlib>
 
+#include <stdlib.h>
+#include <limits.h>
+
 #include "ascii_util.h"
 #include "cxx_util.h"
 #include "string_util.h"
@@ -92,7 +95,11 @@
 float atof( char const *s ) {
   char *end;
   errno = 0;
+#ifdef WIN32
   float result = std::strtof( s, &end );
+#else
+  float result = strtof( s, &end );
+#endif
   check_parse_number( s, end, &result );
   return result;
 }
@@ -100,7 +107,11 @@
 long long atoll( char const *s ) {
   char *end;
   errno = 0;
+#ifdef WIN32
   long long const result = std::strtoll( s, &end, 10 );
+#else
+  long long const result = strtoll( s, &end, 10 );
+#endif
   check_parse_number( s, end, static_cast<long long*>( nullptr ) );
   return result;
 }
@@ -114,7 +125,11 @@
 
   char *end;
   errno = 0;
+#ifdef WIN32
   unsigned long long const result = std::strtoull( s, &end, 10 );
+#else
+  unsigned long long const result = strtoull( s, &end, 10 );
+#endif
   check_parse_number( s, end, static_cast<unsigned long long*>( nullptr ) );
 
   if ( minus && result ) {
