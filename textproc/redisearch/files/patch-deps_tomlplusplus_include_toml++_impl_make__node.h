--- deps/tomlplusplus/include/toml++/impl/make_node.h.orig	2026-05-30 14:13:54 UTC
+++ deps/tomlplusplus/include/toml++/impl/make_node.h
@@ -134,6 +134,18 @@ TOML_IMPL_NAMESPACE_START
 		return node_ptr{ make_node_impl(static_cast<T&&>(val), flags) };
 	}
 
+	TOML_NODISCARD
+	inline node_ptr make_node(node_ptr&& val, value_flags flags = preserve_source_value_flags)
+	{
+        return std::move(val);
+	}
+
+	TOML_NODISCARD
+	inline node_ptr make_node(const node_ptr& val, value_flags flags = preserve_source_value_flags)
+	{
+        return make_node(*val);
+	}
+
 	template <typename... T>
 	struct emplaced_type_of_
 	{
