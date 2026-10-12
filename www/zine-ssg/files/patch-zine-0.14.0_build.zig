--- zine-0.14.0/build.zig.orig	2026-09-03 11:17:42 UTC
+++ zine-0.14.0/build.zig
@@ -148,17 +148,11 @@ pub fn build(b: *std.Build) !void {
     const target = b.standardTargetOptions(.{});
     const optimize = b.standardOptimizeOption(.{});
 
-    const no_git_version = b.option(
-        bool,
-        "no-git-version",
-        "Disable git version detection, useful when using Zine as a dependency",
-    ) orelse false;
-
     const version = b.option(
         []const u8,
         "version",
         "Override the Zine version, use with care!",
-    ) orelse getVersion(b, no_git_version);
+    ) orelse "%%DISTVERSION%%";
 
     const preview = b.option(bool, "preview", "Allow creating release builds of a '-dev' version") orelse false;
 
@@ -315,7 +309,7 @@ pub fn build(b: *std.Build) !void {
         .netbsd => {},
         .freebsd => {
             // only required for FreeBSD < 15
-            // zine_exe.linkSystemLibrary("inotify");
+            %INOTIFY_GUARD%zine_exe.linkSystemLibrary("inotify");
         },
         .windows => {},
         .macos => {
@@ -550,12 +544,12 @@ fn setupReleaseStep(
     const targets: []const std.Target.Query = &.{
         .{ .cpu_arch = .aarch64, .os_tag = .macos },
         .{ .cpu_arch = .aarch64, .os_tag = .linux, .abi = .musl },
-        .{ .cpu_arch = .aarch64, .os_tag = .freebsd, .os_version_min = .{ .semver = .{ .major = 15, .minor = 0, .patch = 0 } } },
+        .{ .cpu_arch = .aarch64, .os_tag = .freebsd },
         .{ .cpu_arch = .aarch64, .os_tag = .netbsd },
         .{ .cpu_arch = .aarch64, .os_tag = .windows },
         .{ .cpu_arch = .x86_64, .os_tag = .macos },
         .{ .cpu_arch = .x86_64, .os_tag = .linux, .abi = .musl },
-        .{ .cpu_arch = .x86_64, .os_tag = .freebsd, .os_version_min = .{ .semver = .{ .major = 15, .minor = 0, .patch = 0 } } },
+        .{ .cpu_arch = .x86_64, .os_tag = .freebsd },
         .{ .cpu_arch = .x86_64, .os_tag = .netbsd },
         .{ .cpu_arch = .x86_64, .os_tag = .windows },
     };
@@ -671,7 +665,7 @@ fn setupReleaseStep(
             .netbsd => {},
             .freebsd => {
                 // only required for FreeBSD < 15
-                // zine_exe_release.linkSystemLibrary("inotify");
+                %INOTIFY_GUARD%zine_exe_release.linkSystemLibrary("inotify");
             },
             .windows => {},
             .macos => {
