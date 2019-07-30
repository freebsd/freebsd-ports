--- Server/src/Logger.h.orig	2019-07-20 08:42:40 UTC
+++ Server/src/Logger.h
@@ -13,6 +13,7 @@
 #include <iostream>
 #include <cstdint>
 
+#include <sys/types.h>
 
 /*
  * DEBUG is a macro for DebugPrint with FILE, LINE, FUNCTION added
