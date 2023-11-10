--- src/base/RandomUuid.cc.orig	2023-02-28 09:10:25 UTC
+++ src/base/RandomUuid.cc
@@ -13,6 +13,7 @@
 #include "base/TextException.h"
 #include "defines.h"
 
+#include <netinet/in.h>
 #include <iostream>
 
 static_assert(sizeof(RandomUuid) == 128/8, "RandomUuid has RFC 4122-prescribed 128-bit size");
