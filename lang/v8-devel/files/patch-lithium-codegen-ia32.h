--- src/ia32/lithium-codegen-ia32.h.orig	2013-12-28 22:35:15.000000000 +0800
+++ src/ia32/lithium-codegen-ia32.h	2013-12-28 22:35:41.000000000 +0800
@@ -426,7 +426,7 @@ class LCodeGen: public LCodeGenBase {
     explicit X87Stack(MacroAssembler* masm)
         : stack_depth_(0), is_mutable_(true), masm_(masm) { }
     explicit X87Stack(const X87Stack& other)
-        : stack_depth_(other.stack_depth_), is_mutable_(false), masm_(masm()) {
+        : stack_depth_(other.stack_depth_), is_mutable_(false), masm_(NULL) {
       for (int i = 0; i < stack_depth_; i++) {
         stack_[i] = other.stack_[i];
       }
