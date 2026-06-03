--- torch/csrc/jit/ir/attributes.h.orig	2026-04-18 20:22:08 UTC
+++ torch/csrc/jit/ir/attributes.h
@@ -66,6 +66,9 @@ struct ScalarAttributeValue : public AttributeValue {
 struct ScalarAttributeValue : public AttributeValue {
   using ConstructorType = T;
   using ValueType = T;
+  // kAttrKind lets getAttr<T> verify the runtime kind without dynamic_cast,
+  // working around FreeBSD libcxxrt pointer-based RTTI across DSO boundaries.
+  static constexpr AttributeKind kAttrKind = Kind;
   ScalarAttributeValue(Symbol name, ConstructorType value_)
       : AttributeValue(name), value_(std::move(value_)) {}
   ValueType& value() {
@@ -86,6 +89,7 @@ struct VectorAttributeValue : public AttributeValue {
 struct VectorAttributeValue : public AttributeValue {
   using ConstructorType = std::vector<T>;
   using ValueType = std::vector<T>;
+  static constexpr AttributeKind kAttrKind = Kind;
   VectorAttributeValue(Symbol name, ConstructorType value_)
       : AttributeValue(name), value_(std::move(value_)) {}
   ValueType& value() {
@@ -126,6 +130,7 @@ struct TORCH_API GraphAttr : public AttributeValue {
 struct TORCH_API GraphAttr : public AttributeValue {
   using ConstructorType = std::shared_ptr<Graph>;
   using ValueType = std::shared_ptr<Graph>;
+  static constexpr AttributeKind kAttrKind = AttributeKind::g;
   GraphAttr(Symbol name, ConstructorType value_)
       : AttributeValue(name), value_(std::move(value_)) {}
   ValueType& value() {
@@ -143,6 +148,7 @@ struct TORCH_API GraphsAttr : public AttributeValue {
 struct TORCH_API GraphsAttr : public AttributeValue {
   using ConstructorType = std::vector<std::shared_ptr<Graph>>;
   using ValueType = std::vector<std::shared_ptr<Graph>>;
+  static constexpr AttributeKind kAttrKind = AttributeKind::gs;
   GraphsAttr(Symbol name, ConstructorType value_)
       : AttributeValue(name), value_(std::move(value_)) {}
   ValueType& value() {
