--- src/cpp-ethereum/libdevcore/Common.cpp.orig	2019-09-18 13:47:22 UTC
+++ src/cpp-ethereum/libdevcore/Common.cpp
@@ -24,6 +24,7 @@
 #endif
 
 #include <aleth/buildinfo.h>
+#include <clocale> /* std::setlocale */
 
 using namespace std;
 
