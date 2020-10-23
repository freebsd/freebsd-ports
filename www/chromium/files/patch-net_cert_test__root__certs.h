--- net/cert/test_root_certs.h.orig	2020-09-08 19:14:08 UTC
+++ net/cert/test_root_certs.h
@@ -75,7 +75,7 @@
   // engine is appropriate. The caller is responsible for freeing the
   // returned HCERTCHAINENGINE.
   HCERTCHAINENGINE GetChainEngine() const;
-#elif defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_BSD) || defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS)
   TrustStore* test_trust_store() { return &test_trust_store_; }
 #endif
 
@@ -93,12 +93,12 @@
 #elif defined(OS_MACOSX)
   base::ScopedCFTypeRef<CFMutableArrayRef> temporary_roots_;
   TrustStoreInMemory test_trust_store_;
-#elif defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_BSD) || defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS)
   TrustStoreInMemory test_trust_store_;
 #endif
 
 #if defined(OS_WIN) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
-    defined(OS_LINUX) || defined(OS_CHROMEOS)
+    defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // True if there are no temporarily trusted root certificates.
   bool empty_ = true;
 #endif
