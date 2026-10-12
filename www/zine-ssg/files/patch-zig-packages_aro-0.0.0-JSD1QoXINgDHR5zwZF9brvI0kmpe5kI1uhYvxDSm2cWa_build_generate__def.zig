--- zig-packages/aro-0.0.0-JSD1QoXINgDHR5zwZF9brvI0kmpe5kI1uhYvxDSm2cWa/build/generate_def.zig.orig	2026-10-11 00:30:13 UTC
+++ zig-packages/aro-0.0.0-JSD1QoXINgDHR5zwZF9brvI0kmpe5kI1uhYvxDSm2cWa/build/generate_def.zig
@@ -424,7 +424,7 @@ const DafsaBuilder = struct {
         var node = if (db.unchecked_nodes.items.len == 0)
             db.root
         else
-            db.unchecked_nodes.getLast().?.child;
+            db.unchecked_nodes.last().?.child;
 
         for (str[common_prefix_len..]) |c| {
             std.debug.assert(node.children[c] == null);
