--- src/cpp-ethereum/libevm/LegacyVM.cpp.orig	2019-09-18 13:47:22 UTC
+++ src/cpp-ethereum/libevm/LegacyVM.cpp
@@ -17,6 +17,10 @@
 
 #include "LegacyVM.h"
 
+#ifdef MSIZE
+#undef MSIZE
+#endif /* MSIZE */
+
 using namespace std;
 using namespace dev;
 using namespace dev::eth;
