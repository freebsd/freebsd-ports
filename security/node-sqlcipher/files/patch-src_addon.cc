--- src/addon.cc.orig	2025-04-10 22:08:02 UTC
+++ src/addon.cc
@@ -7,7 +7,7 @@
 #include "addon.h"
 
 #include "napi.h"
-#include "signal-tokenizer.h"
+#include <signal-tokenizer.h>
 #include "sqlite3.h"
 
 // Signal Tokenizer
