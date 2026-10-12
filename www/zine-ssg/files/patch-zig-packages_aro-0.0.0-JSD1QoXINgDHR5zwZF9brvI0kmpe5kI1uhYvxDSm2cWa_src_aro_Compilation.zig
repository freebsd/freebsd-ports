--- zig-packages/aro-0.0.0-JSD1QoXINgDHR5zwZF9brvI0kmpe5kI1uhYvxDSm2cWa/src/aro/Compilation.zig.orig	2026-10-11 01:16:12 UTC
+++ zig-packages/aro-0.0.0-JSD1QoXINgDHR5zwZF9brvI0kmpe5kI1uhYvxDSm2cWa/src/aro/Compilation.zig
@@ -1797,6 +1797,7 @@ pub fn addSourceFromOwnedBuffer(comp: *Compilation, pa
 
     if (i != contents.len) {
         var list: std.ArrayList(u8) = .{
+            .pointer_stability = .{},
             .items = contents[0..i],
             .capacity = contents.len + 1, // +1 for sentinel
         };
