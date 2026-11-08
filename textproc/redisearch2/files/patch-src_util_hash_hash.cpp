--- src/util/hash/hash.cpp.orig	2026-09-30 14:30:41 UTC
+++ src/util/hash/hash.cpp
@@ -4,7 +4,11 @@ void Sha1_Compute(const char *value, size_t len, Sha1*
 void Sha1_Compute(const char *value, size_t len, Sha1* output) {
   boost::uuids::detail::sha1 sha1;
   sha1.process_bytes(value, len);
-  sha1.get_digest(output->hash);
+  boost::uuids::detail::sha1::digest_type digest;
+  sha1.get_digest(digest);
+  for (int i = 0; i < 5; i++) {
+      output->hash[i] = ((uint32_t)digest[i * 4] << 24) | ((uint32_t)digest[i * 4 + 1] << 16) | ((uint32_t)digest[i * 4 + 2] << 8) | (uint32_t)digest[i * 4 + 3];
+  }
 }
 
 void Sha1_FormatIntoBuffer(const Sha1 *sha1, char *buffer) {
