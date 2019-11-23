--- src/3rdparty/chromium/base/sha1.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/base/sha1.cc
@@ -110,8 +110,10 @@ void SecureHashAlgorithm::Final() {
   Pad();
   Process();
 
+#if defined(ARCH_CPU_LITTLE_ENDIAN)
   for (auto& t : H)
     t = ByteSwap(t);
+#endif
 }
 
 void SecureHashAlgorithm::Update(const void* data, size_t nbytes) {
@@ -157,8 +159,10 @@ void SecureHashAlgorithm::Process() {
   //
   // W and M are in a union, so no need to memcpy.
   // memcpy(W, M, sizeof(M));
+#if defined(ARCH_CPU_LITTLE_ENDIAN)
   for (t = 0; t < 16; ++t)
     W[t] = ByteSwap(W[t]);
+#endif
 
   // b.
   for (t = 16; t < 80; ++t)
