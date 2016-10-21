--- src/pycrypto_common.h.orig	2016-10-19 06:31:57 UTC
+++ src/pycrypto_common.h
@@ -45,7 +45,7 @@ typedef unsigned __int64 uint64_t;
 
 #else
 #include <stdint.h>
-#include <alloca.h>
+//#include <alloca.h>
 #endif
 
 #include <stdlib.h>
