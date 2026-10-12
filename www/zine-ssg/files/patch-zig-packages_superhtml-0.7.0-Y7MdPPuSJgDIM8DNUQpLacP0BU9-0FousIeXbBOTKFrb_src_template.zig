--- zig-packages/superhtml-0.7.0-Y7MdPPuSJgDIM8DNUQpLacP0BU9-0FousIeXbBOTKFrb/src/template.zig.orig	2026-10-11 02:18:37 UTC
+++ zig-packages/superhtml-0.7.0-Y7MdPPuSJgDIM8DNUQpLacP0BU9-0FousIeXbBOTKFrb/src/template.zig
@@ -1242,12 +1242,12 @@ pub fn SuperTemplate(comptime ScriptyVM: type) type {
         }
 
         pub fn setContext(tpl: Template, script_ctx: RootRef) void {
-            script_ctx.loop = if (tpl.loop_stack.getLast()) |last|
+            script_ctx.loop = if (tpl.loop_stack.last()) |last|
                 last.iterator
             else
                 null;
 
-            script_ctx.@"if" = if (tpl.if_stack.getLast()) |last|
+            script_ctx.@"if" = if (tpl.if_stack.last()) |last|
                 last.value
             else
                 null;
