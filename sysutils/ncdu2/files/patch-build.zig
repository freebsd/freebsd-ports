--- build.zig.orig	2023-08-04 10:43:27 UTC
+++ build.zig
@@ -8,6 +8,7 @@ pub fn build(b: *std.Build) void {
     const optimize = b.standardOptimizeOption(.{});
 
     const pie = b.option(bool, "pie", "Build with PIE support (by default false)") orelse false;
+    const strip = b.option(bool, "strip", "Omit debug information (by default false)") orelse false;
 
     const exe = b.addExecutable(.{
         .name = "ncdu",
@@ -23,6 +24,7 @@ pub fn build(b: *std.Build) void {
     }
     linkNcurses(exe);
     exe.pie = pie;
+    exe.strip = strip;
     b.installArtifact(exe);
 
     const run_cmd = b.addRunArtifact(exe);
@@ -41,6 +43,7 @@ pub fn build(b: *std.Build) void {
     });
     linkNcurses(unit_tests);
     unit_tests.pie = pie;
+    unit_tests.strip = strip;
 
     const run_unit_tests = b.addRunArtifact(unit_tests);
 
