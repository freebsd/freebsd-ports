--- zig-packages/translate_c-0.0.0-Q_BUWjQ7BwAhlMt3Zf4l3Jw-y0_TOpJWgcK8rk4d0aWv/src/Translator.zig.orig	2026-07-25 12:54:04 UTC
+++ zig-packages/translate_c-0.0.0-Q_BUWjQ7BwAhlMt3Zf4l3Jw-y0_TOpJWgcK8rk4d0aWv/src/Translator.zig
@@ -769,7 +769,7 @@ fn transFnDecl(t: *Translator, scope: *Scope, function
     }
 
     // TODO actually set with @export/@extern
-    const linkage = t.tree.linkage(decl_node);
+    const linkage = t.declLinkage(decl_node);
     if (linkage != .strong) {
         try t.warn(scope, fn_decl_loc, "TODO {s} linkage ignored", .{@tagName(linkage)});
     }
@@ -957,7 +957,7 @@ fn transVarDecl(t: *Translator, scope: *Scope, variabl
     const linksection_string = if (t.tree.attr_map.getAttribute(decl_node, .section)) |attr| attr.args.section else null;
 
     // TODO actually set with @export/@extern
-    const linkage = t.tree.linkage(decl_node);
+    const linkage = t.declLinkage(decl_node);
     if (linkage != .strong) {
         try t.warn(scope, variable.name_tok, "TODO {s} linkage ignored", .{@tagName(linkage)});
     }
@@ -1016,6 +1016,13 @@ fn transVarDecl(t: *Translator, scope: *Scope, variabl
             try bs.statements.append(t.gpa, deferred_cleanup);
         }
     }
+}
+
+fn declLinkage(t: *const Translator, node: Node.Index) std.builtin.GlobalLinkage {
+    const am = &t.tree.attr_map;
+    if (am.hasAttribute(node, .weak)) return .weak;
+    if (am.hasAttribute(node, .selectany)) return .weak;
+    return .strong;
 }
 
 fn transEnumDecl(t: *Translator, scope: *Scope, enum_qt: QualType) Error!void {
