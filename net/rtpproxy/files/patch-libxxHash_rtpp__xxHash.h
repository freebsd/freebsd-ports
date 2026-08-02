--- libxxHash/rtpp_xxHash.h.orig	2026-08-02 15:45:18 UTC
+++ libxxHash/rtpp_xxHash.h
@@ -27,4 +27,4 @@
 
 #pragma once
 #define XXH_INLINE_ALL
-#include "../external/xxHash/xxhash.h"
+#include <xxhash.h>
