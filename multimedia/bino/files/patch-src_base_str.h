--- src/base/str.h.orig	2017-11-04 13:56:43 UTC
+++ src/base/str.h
@@ -31,6 +31,7 @@
 #include <vector>
 #include <cstdarg>
 #include <cerrno>
+#include <ctime>
 
 #ifdef __GNUC__
 # define STR_AFP(a, b) __attribute__ ((format (printf, a, b)))
