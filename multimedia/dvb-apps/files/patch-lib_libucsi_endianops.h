--- lib/libucsi/endianops.h.orig	2014-03-21 19:26:36 UTC
+++ lib/libucsi/endianops.h
@@ -27,8 +27,6 @@ extern "C"
 #endif
 
 #include <stdint.h>
-#include <byteswap.h>
-#include <endian.h>
 
 #define __ucsi_packed __attribute__((packed))
 
