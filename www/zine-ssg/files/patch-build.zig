--- build.zig.orig	2025-11-21 13:41:48 UTC
+++ build.zig
@@ -309,6 +309,11 @@ pub fn build(b: *std.Build) !void {
         else => @panic("target must be added to build.zig"),
         .linux => {},
 
+	.freebsd => {
+            // only added for FreeBSD < 15
+            %INOTIFY_GUARD%zine_exe.linkSystemLibrary("inotify");
+         },
+
         .windows => {
             zine_exe.linkSystemLibrary("ws2_32");
         },
@@ -519,8 +524,10 @@ fn setupReleaseStep(
     const targets: []const std.Target.Query = &.{
         .{ .cpu_arch = .aarch64, .os_tag = .macos },
         .{ .cpu_arch = .aarch64, .os_tag = .linux, .abi = .musl },
+        .{ .cpu_arch = .aarch64, .os_tag = .freebsd },
         .{ .cpu_arch = .x86_64, .os_tag = .macos },
         .{ .cpu_arch = .x86_64, .os_tag = .linux, .abi = .musl },
+        .{ .cpu_arch = .x86_64, .os_tag = .freebsd },
         .{ .cpu_arch = .x86_64, .os_tag = .windows },
         .{ .cpu_arch = .aarch64, .os_tag = .windows },
     };
@@ -626,6 +633,10 @@ fn setupReleaseStep(
         switch (target.result.os.tag) {
             else => @panic("target must be added to build.zig"),
             .linux => {},
+            .freebsd => {
+                // only added for FreeBSD < 15
+                %INOTIFY_GUARD%zine_exe_release.linkSystemLibrary("inotify");
+            },
             .windows => {
                 zine_exe_release.linkSystemLibrary("ws2_32");
             },
