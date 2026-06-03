--- src/include/fst/fst.h.orig	2026-03-22 05:51:04 UTC
+++ src/include/fst/fst.h
@@ -652,8 +652,8 @@ class FstImpl {
   FstImpl &operator=(const FstImpl<Arc> &impl) {
     properties_ = impl.properties_;
     type_ = impl.type_;
-    isymbols_ = impl.isymbols_ ? impl.isymbols_->Copy() : nullptr;
-    osymbols_ = impl.osymbols_ ? impl.osymbols_->Copy() : nullptr;
+    isymbols_.reset(impl.isymbols_ ? impl.isymbols_->Copy() : nullptr);
+    osymbols_.reset(impl.osymbols_ ? impl.osymbols_->Copy() : nullptr);
     return *this;
   }
 
