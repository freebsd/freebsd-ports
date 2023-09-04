--- build.zig.orig	2023-01-19 06:57:48 UTC
+++ build.zig
@@ -13,6 +13,7 @@ pub fn build(b: *std.build.Builder) void {
     exe.addCSourceFile("src/ncurses_refs.c", &[_][]const u8{});
     exe.linkLibC();
     exe.linkSystemLibrary("ncursesw");
+    exe.strip = b.option(bool, "strip", "Strip debug information") orelse false;
     exe.install();
 
     const run_cmd = exe.run();
