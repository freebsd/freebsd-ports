--- src/rpc/names.cpp.orig	2023-02-23 16:44:43.398660000 +0000
+++ src/rpc/names.cpp	2023-02-23 16:44:58.322833000 +0000
@@ -20,6 +20,7 @@
 #include <rpc/server_util.h>
 #include <script/names.h>
 #include <txmempool.h>
+#include <util/system.h>
 #include <util/strencodings.h>
 #include <validation.h>
 #ifdef ENABLE_WALLET
