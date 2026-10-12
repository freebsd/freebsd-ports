--- zig-packages/aro-0.0.0-JSD1QoXINgDHR5zwZF9brvI0kmpe5kI1uhYvxDSm2cWa/src/aro/Tree.zig.orig	2026-10-11 01:42:15 UTC
+++ zig-packages/aro-0.0.0-JSD1QoXINgDHR5zwZF9brvI0kmpe5kI1uhYvxDSm2cWa/src/aro/Tree.zig
@@ -3188,14 +3188,6 @@ pub fn calledFunctionAttr(tree: *const Tree, node: Nod
     }
 }
 
-pub fn linkage(tree: *const Tree, node: Node.Index) std.builtin.GlobalLinkage {
-    const am = &tree.attr_map;
-    if (am.hasAttribute(node, .internal_linkage)) return .internal;
-    if (am.hasAttribute(node, .weak)) return .weak;
-    if (am.hasAttribute(node, .selectany)) return .link_once;
-    return .strong;
-}
-
 pub fn isLval(tree: *const Tree, node: Node.Index) bool {
     var is_const: bool = undefined;
     return tree.isLvalExtra(node, &is_const);
