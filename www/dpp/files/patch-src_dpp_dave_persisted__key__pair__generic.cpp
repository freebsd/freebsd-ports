- workaround for https://github.com/brainboxdotcc/DPP/issues/1323

--- src/dpp/dave/persisted_key_pair_generic.cpp.orig	2024-11-07 05:49:41 UTC
+++ src/dpp/dave/persisted_key_pair_generic.cpp
@@ -38,6 +38,7 @@
 #include <bytes/bytes.h>
 #include <mls/crypto.h>
 #include <dpp/cluster.h>
+#include <sys/stat.h>
 #include "parameters.h"
 #include "persisted_key_pair.h"
 
