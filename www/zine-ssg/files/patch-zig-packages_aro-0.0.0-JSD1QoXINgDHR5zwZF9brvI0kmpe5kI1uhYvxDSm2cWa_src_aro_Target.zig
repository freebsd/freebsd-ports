--- zig-packages/aro-0.0.0-JSD1QoXINgDHR5zwZF9brvI0kmpe5kI1uhYvxDSm2cWa/src/aro/Target.zig.orig	2026-07-25 11:38:59 UTC
+++ zig-packages/aro-0.0.0-JSD1QoXINgDHR5zwZF9brvI0kmpe5kI1uhYvxDSm2cWa/src/aro/Target.zig
@@ -1067,6 +1067,7 @@ pub fn get32BitArchVariant(target: *const Target) ?Tar
         .riscv32be,
         .sh,
         .sheb,
+        .spork8,
         .sparc,
         .spirv32,
         .thumb,
@@ -1118,6 +1119,7 @@ pub fn get64BitArchVariant(target: *const Target) ?Tar
         .propeller,
         .sh,
         .sheb,
+        .spork8,
         .xcore,
         .xtensa,
         .xtensaeb,
@@ -1237,6 +1239,7 @@ pub fn toLLVMTriple(target: *const Target, buf: []u8) 
         .propeller => "propeller",
         .sh => "sh",
         .sheb => "sheb",
+        .spork8 => "spork8",
         .x86_16 => "i86",
         .xtensaeb => "xtensaeb",
     };
@@ -1290,6 +1293,7 @@ pub fn toLLVMTriple(target: *const Target, buf: []u8) 
         .psx,
         .tios,
         .ashetos,
+        .gba,
         .vita,
         => "unknown",
     };
@@ -1629,15 +1633,15 @@ pub fn cCharSignedness(target: *const Target) std.buil
 }
 
 pub fn cCharSignedness(target: *const Target) std.builtin.Signedness {
-    return target.toZigTarget().cCharSignedness();
+    return target.toZigTarget().cCharSignedness().?;
 }
 
 pub fn cTypeBitSize(target: *const Target, c_type: std.Target.CType) u16 {
-    return target.toZigTarget().cTypeBitSize(c_type);
+    return target.toZigTarget().cTypeBitSize(c_type).?;
 }
 
 pub fn cTypeAlignment(target: *const Target, c_type: std.Target.CType) u16 {
-    return target.toZigTarget().cTypeAlignment(c_type);
+    return target.toZigTarget().cTypeAlignment(c_type).?;
 }
 
 pub fn standardDynamicLinkerPath(target: *const Target) std.Target.DynamicLinker {
