--- src/rpsl/rpsl/prefix.hh.orig	2004-07-30 12:58:14.000000000 +0200
+++ src/rpsl/rpsl/prefix.hh
@@ -59,7 +59,11 @@
 #include <sys/types.h>
 #include <vector>
 #include <sstream>
+#if (__GNUC__ > 2)
 #include <ostream>
+#else
+#include <ostream.h>
+#endif
 
 typedef unsigned long long int       ip_v6word_t;
 
