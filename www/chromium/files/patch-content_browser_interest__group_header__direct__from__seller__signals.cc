--- content/browser/interest_group/header_direct_from_seller_signals.cc.orig	2023-11-03 10:09:45 UTC
+++ content/browser/interest_group/header_direct_from_seller_signals.cc
@@ -206,7 +206,11 @@ void OnJsonDecoded(
 
 }  // namespace
 
+#if defined(__clang__) && (__clang_major__ >= 16)
 HeaderDirectFromSellerSignals::HeaderDirectFromSellerSignals() = default;
+#else
+HeaderDirectFromSellerSignals::HeaderDirectFromSellerSignals() {}
+#endif
 
 HeaderDirectFromSellerSignals::~HeaderDirectFromSellerSignals() = default;
 
