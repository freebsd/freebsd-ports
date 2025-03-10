--- src/include/fst/fst.h.orig	2021-02-07 08:38:45 UTC
+++ src/include/fst/fst.h
@@ -701,8 +701,8 @@ class FstImpl {
     properties_.store(impl.properties_.load(std::memory_order_relaxed),
                       std::memory_order_relaxed);
     type_ = impl.type_;
-    isymbols_ = impl.isymbols_ ? impl.isymbols_->Copy() : nullptr;
-    osymbols_ = impl.osymbols_ ? impl.osymbols_->Copy() : nullptr;
+    isymbols_.reset(impl.isymbols_ ? impl.isymbols_->Copy() : nullptr);
+    osymbols_.reset(impl.osymbols_ ? impl.osymbols_->Copy() : nullptr);
     return *this;
   }
 
