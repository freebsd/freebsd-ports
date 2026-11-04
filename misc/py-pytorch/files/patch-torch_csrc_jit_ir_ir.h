--- torch/csrc/jit/ir/ir.h.orig	2026-10-28 18:16:03 UTC
+++ torch/csrc/jit/ir/ir.h
@@ -959,13 +959,24 @@ struct TORCH_API Node {
   typename T::ValueType& getAttr(Symbol name) const {
     AT_ASSERT(name.is_attr());
     auto it = findAttr(name, true);
-    auto* child = dynamic_cast<T*>(it->get());
+    auto* base = it->get();
+#if defined(__FreeBSD__)
+    // FreeBSD's libcxxrt uses pointer-based typeinfo comparison; dynamic_cast
+    // across DSO boundaries fails for template specialisations whose typeinfo
+    // symbol is HIDDEN (not exported).  Use kind() + static_cast instead.
+    if (base->kind() != T::kAttrKind) {
+      throw IRAttributeError(name, true);
+    }
+    return static_cast<T*>(base)->value();
+#else
+    auto* child = dynamic_cast<T*>(base);
     TORCH_CHECK(
         child != nullptr,
         "required keyword attribute '",
         name.toUnqualString(),
         "' has the wrong type");
     return child->value();
+#endif
   }
   using AVPtr = AttributeValue::Ptr;
   // NB: For determinism, we use a vector rather than a hash map.  This does
