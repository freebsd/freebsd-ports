--- content/browser/interest_group/header_direct_from_seller_signals.cc.orig	2023-09-13 12:11:42 UTC
+++ content/browser/interest_group/header_direct_from_seller_signals.cc
@@ -187,7 +187,11 @@ void OnJsonDecoded(std::unique_ptr<const std::set<std:
 
 }  // namespace
 
+#if defined(__clang__) && (__clang_major__ >= 16)
 HeaderDirectFromSellerSignals::HeaderDirectFromSellerSignals() = default;
+#else
+HeaderDirectFromSellerSignals::HeaderDirectFromSellerSignals() {}
+#endif
 
 HeaderDirectFromSellerSignals::~HeaderDirectFromSellerSignals() = default;
 
