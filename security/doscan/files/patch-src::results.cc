--- src/results.cc.orig	Fri Oct 31 13:41:03 2003
+++ src/results.cc	Tue Nov  4 09:29:05 2003
@@ -392,7 +392,7 @@
 #ifdef GETHOSTBYADDR_ACCEPTS_CHAR
   he = gethostbyaddr (reinterpret_cast<char*>(&in), sizeof (in), AF_INET);
 #else
-#error Type of first argument to gethostbyaddr() is not known.
+  he = gethostbyaddr ((const char*)(&in), sizeof (in), AF_INET);
 #endif
 #endif
 
