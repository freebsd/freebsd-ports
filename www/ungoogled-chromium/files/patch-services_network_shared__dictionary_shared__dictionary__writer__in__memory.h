--- services/network/shared_dictionary/shared_dictionary_writer_in_memory.h.orig	2023-06-05 19:39:05 UTC
+++ services/network/shared_dictionary/shared_dictionary_writer_in_memory.h
@@ -5,6 +5,8 @@
 #ifndef SERVICES_NETWORK_SHARED_DICTIONARY_SHARED_DICTIONARY_WRITER_IN_MEMORY_H_
 #define SERVICES_NETWORK_SHARED_DICTIONARY_SHARED_DICTIONARY_WRITER_IN_MEMORY_H_
 
+#include <vector>
+
 #include "base/component_export.h"
 #include "base/functional/callback.h"
 #include "crypto/secure_hash.h"
