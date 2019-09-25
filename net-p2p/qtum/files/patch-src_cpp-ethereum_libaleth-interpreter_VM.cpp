--- src/cpp-ethereum/libaleth-interpreter/VM.cpp.orig	2019-09-18 13:47:22 UTC
+++ src/cpp-ethereum/libaleth-interpreter/VM.cpp
@@ -20,6 +20,10 @@
 
 #include <aleth/buildinfo.h>
 
+#ifdef MSIZE
+#undef MSIZE
+#endif /* MSIZE */
+
 namespace
 {
 void destroy(evmc_instance* _instance)
